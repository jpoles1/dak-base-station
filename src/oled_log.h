#include "SSD1306.h"
#include <Wire.h>

#include <bits/stdc++.h>
#include <iostream>
#include <sstream>
#include <string>

SSD1306 display(0x3c, 5, 4);

std::vector<std::string> splitString(std::string input, unsigned string_size = 10) {
    std::vector<std::string> split_string;
    for (unsigned i = 0; i < input.length(); i += string_size) {
        split_string.push_back(input.substr(i, string_size));
    }
    return split_string;
}

void displayString(std::string display_data, bool newline = true, bool clearScreen = false) {
    if (clearScreen == true) {
        display.setLogBuffer(5, 30);
    }
    std::vector<std::string> split_string = splitString(display_data, 21);
    for (std::vector<std::string>::iterator it = split_string.begin();
            it != split_string.end(); ++it) {
        display.clear();
        std::string txt = *it;
        char *cstr = new char[txt.length() + 1];
        strcpy(cstr, txt.c_str());
        if (newline) {
            Serial.println(cstr);
            display.println(cstr);
        } else {
            Serial.print(cstr);
            display.print(cstr);
        }
        delete[] cstr;
        // Draw it to the internal screen buffer
        display.drawLogBuffer(0, 0);
        // Display it on the screen
        display.display();
    }
    // Print to the screen
    if (newline) {
        delay(50);
    }
}

void displayInt(int display_data, bool newline = false, bool clearScreen = false) {
    std::ostringstream ss;
    ss.str("");
    ss << display_data;
    displayString(ss.str(), newline, clearScreen);
}

void displayStringVector(std::vector<std::string> display_data,
                         bool clearScreen = false) {
    if (clearScreen == true) {
        display.setLogBuffer(5, 30);
    }
    for (std::vector<std::string>::iterator it = display_data.begin();
            it != display_data.end(); ++it) {
        // Print to the screen
        displayString(*it, true, clearScreen);
    }
}
