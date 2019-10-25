//Private Config
#include "config.h"

//Libs
#include <WiFi.h>
#include "esp_wpa2.h"
#include <WebSocketClient.h>
#include "RCSwitch.h"
#include <oled_log.h>

//Pins
#define TRANSMITTER_PIN 16

//Global variables
WebSocketClient webSocketClient;
WiFiClient client;
RCSwitch transmitter433 = RCSwitch();

void wifiCheck(){
    if(WiFi.status() != WL_CONNECTED){
        displayString("Connecting to WiFi...", false);
    }
    int counter = 0;
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        displayString(".", false);
        counter++;
        if(counter>=60){ //after 30 seconds timeout - reset board
            ESP.restart();
        }
    }
    displayString(" ");
}

void websocketLoad() {
    wifiCheck();
    if (client.connect(WEBSOCKET_URL, 80)) {
        displayString("WebSocket connected!");
    } else {
        displayString("WebSocket connection failed!");
    }
    String wsURL = String("/sync?room=jp-bedroom&key=") + SERVER_KEY;
    webSocketClient.path = const_cast<char*>(wsURL.c_str());
    webSocketClient.host = strdup(WEBSOCKET_URL);
    if (webSocketClient.handshake(client)) {
        displayString("WebSocket handshake successful!");
    } else {
        displayString("WebSocket handshake failed!");
    }
}

void setup() {
    Serial.begin(115200);
    delay(10);
    //Setup OLED display
    display.init();
    // display.flipScreenVertically();
    display.setContrast(255);
    display.setLogBuffer(5, 30);
    //Setup 433 mhz transmitter
    transmitter433.enableTransmit(TRANSMITTER_PIN);
    transmitter433.setPulseLength(140);
    transmitter433.setRepeatTransmit(5);
    //Setup wifi
    //uint8_t new_mac[8] = {0x39,0xAE,0xA4,0x16,0x1F,0x08};
    //esp_base_mac_addr_set(new_mac);
    WiFi.disconnect(true);  //disconnect form wifi to set new wifi connection
    WiFi.mode(WIFI_STA); //init wifi mode
    esp_wifi_sta_wpa2_ent_set_identity((uint8_t *)EAP_IDENTITY, strlen(EAP_IDENTITY)); //provide identity
    esp_wifi_sta_wpa2_ent_set_username((uint8_t *)EAP_IDENTITY, strlen(EAP_IDENTITY)); //provide username --> identity and username is same
    esp_wifi_sta_wpa2_ent_set_password((uint8_t *)EAP_PASSWORD, strlen(EAP_PASSWORD)); //provide password
    esp_wpa2_config_t config = WPA2_CONFIG_INIT_DEFAULT(); //set config settings to default
    esp_wifi_sta_wpa2_ent_enable(&config); //set config settings to enable function
    WiFi.begin(AP_SSID);
    //WiFi.setHostname("ESPDAK");
    websocketLoad();
}

std::vector<String> splitStringToVector(String msg, char delim){
  std::vector<String> subStrings;
  int j=0;
  for(int i =0; i < msg.length(); i++){
    if(msg.charAt(i) == delim){
      subStrings.push_back(msg.substring(j,i));
      j = i+1;
    }
  }
  subStrings.push_back(msg.substring(j,msg.length())); //to grab the last value of the string
  return subStrings;
}

void send433(std::string command_code, int nRepeat=4, int delayTime = 50) {
    char* code = strdup(command_code.c_str());
    for (int i=0; i<nRepeat; i++) {
        transmitter433.send(code);
        delay(delayTime);
    }
    free(code);
}

std::string getTransmitterCode(std::string deviceName, std::string command) {
    if (deviceName == "1") {
        if(command=="on") {
            //8399462
            return "0100000000010101001100110";
        }
        else if(command=="off") {
            //8399480
            return "0100000000010101001111000";
        }
    }
    else if (deviceName == "2") {
        if(command=="on") {
            //8399750
            return "0100000000010101110000110";
        }
        else if(command=="off") {
            //8399768
            return "0100000000010101110011000";
        }
    }
    else if (deviceName == "3") {
        if(command=="on") {
            //8400390
            return "0100000000010111000000110";
        }
        else if(command=="off") {
            //8400408
            return "0100000000010111000011000";
        }
    }
    return "";
}

String data;
void loop() {
    if (client.connected()) {
        webSocketClient.getData(data);
        if (data.length() > 0) {
            if (data == "ping") {
                webSocketClient.sendData("pong");
            } else {
                std::vector<String> split_string = splitStringToVector(data.c_str(), ':');
                String msgType = split_string[0];
                String deviceName = split_string[1];
                String fname = split_string[2];
                String command = split_string[3];
                displayString(deviceName.c_str(), false);
                displayString(" - ", false);
                displayString(fname.c_str(), false);
                displayString(" - ", false);
                displayString(command.c_str());
                if(fname == "power") {
                    std::string code = getTransmitterCode(deviceName.c_str(), command.c_str());
                    if(code != "") {
                        send433(code);
                    }
                }
            }
        }
        data = "";
    } else {
        displayString("Client disconnected.");
        websocketLoad();
    }
}