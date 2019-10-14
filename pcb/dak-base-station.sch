EESchema Schematic File Version 4
LIBS:dak-base-station-cache
EELAYER 29 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L 1-My~Parts:433_mHz_Receiver J1
U 1 1 5DA2B0F2
P 7400 5350
F 0 "J1" V 7100 5150 50  0000 C CNN
F 1 "433 mHz Receiver" V 7000 5050 50  0000 C CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x04_P2.54mm_Vertical" H 7400 5350 50  0001 C CNN
F 3 "~" H 7400 5350 50  0001 C CNN
	1    7400 5350
	0    -1   -1   0   
$EndComp
$Comp
L 1-My~Parts:433_mHz_Transmitter J2
U 1 1 5DA27D0A
P 7550 2800
F 0 "J2" V 7400 3050 50  0000 C CNN
F 1 "433 mHz Transmitter" V 7300 3100 50  0000 C CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x03_P2.54mm_Vertical" H 7550 2800 50  0001 C CNN
F 3 "~" H 7550 2800 50  0001 C CNN
	1    7550 2800
	0    -1   -1   0   
$EndComp
Wire Wire Line
	7550 3000 7550 2700
Wire Wire Line
	7450 3000 6450 3000
NoConn ~ 7350 3500
NoConn ~ 7200 3500
NoConn ~ 7050 3500
NoConn ~ 6900 3500
NoConn ~ 6750 3500
NoConn ~ 6600 3500
NoConn ~ 7350 5050
NoConn ~ 7200 5050
NoConn ~ 7050 5050
NoConn ~ 6900 5050
NoConn ~ 6750 5050
NoConn ~ 6450 5050
NoConn ~ 6300 5050
NoConn ~ 6150 5050
NoConn ~ 6000 5050
NoConn ~ 5850 5050
Wire Wire Line
	7400 5550 7500 5550
Wire Wire Line
	7600 5550 7600 5300
Wire Wire Line
	7500 5550 7500 5700
Wire Wire Line
	7500 5700 7800 5700
Wire Wire Line
	7800 5050 7650 5050
Connection ~ 7500 5550
Wire Wire Line
	7800 5700 7800 5050
Wire Wire Line
	5550 5300 5550 5050
Wire Wire Line
	7600 5300 5550 5300
$Comp
L 1-My~Parts:ESP32-OLED U1
U 1 1 5DA29FB3
P 6650 4300
F 0 "U1" V 6650 4850 50  0000 C CNN
F 1 "ESP32-OLED" V 6500 4850 50  0000 C CNN
F 2 "1-My Parts:ESP32 OLED" H 6550 5750 50  0001 C CNN
F 3 "" H 6550 5750 50  0001 C CNN
	1    6650 4300
	0    1    1    0   
$EndComp
Wire Wire Line
	6300 2450 7300 2450
Wire Wire Line
	8850 2450 8850 4400
Wire Wire Line
	8850 5900 7300 5900
Wire Wire Line
	7300 5900 7300 5550
Connection ~ 6300 3500
Wire Wire Line
	6300 3500 6300 3600
Wire Wire Line
	6300 2450 6300 3500
Wire Wire Line
	7550 2700 7300 2700
Wire Wire Line
	7300 2700 7300 2450
Connection ~ 7300 2450
Wire Wire Line
	7300 2450 8850 2450
$Comp
L 1-My~Parts:DHT11_Breakout J3
U 1 1 5DA86315
P 8350 4300
F 0 "J3" H 8378 4326 50  0000 L CNN
F 1 "DHT11_Breakout" H 8150 4100 50  0000 L CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x03_P2.54mm_Vertical" H 8350 4300 50  0001 C CNN
F 3 "~" H 8350 4300 50  0001 C CNN
	1    8350 4300
	1    0    0    -1  
$EndComp
Wire Wire Line
	6450 3500 6450 4200
Wire Wire Line
	6450 4200 8150 4200
Wire Wire Line
	8150 4300 7500 4300
Wire Wire Line
	7500 4300 7500 5050
Wire Wire Line
	8150 4400 8850 4400
Connection ~ 8850 4400
Wire Wire Line
	8850 4400 8850 5900
NoConn ~ 6600 5050
NoConn ~ 5400 5050
NoConn ~ 5700 5050
Wire Wire Line
	7650 3000 7650 3300
Wire Wire Line
	7650 3300 7500 3300
Wire Wire Line
	7500 3300 7500 3500
NoConn ~ 7650 3500
Wire Wire Line
	6450 3000 6450 3500
Connection ~ 6450 3500
$Comp
L Mechanical:MountingHole H1
U 1 1 5DA90327
P 4150 3400
F 0 "H1" H 4250 3446 50  0000 L CNN
F 1 "MountingHole" H 4250 3355 50  0000 L CNN
F 2 "MountingHole:MountingHole_3.2mm_M3" H 4150 3400 50  0001 C CNN
F 3 "~" H 4150 3400 50  0001 C CNN
	1    4150 3400
	1    0    0    -1  
$EndComp
$Comp
L Mechanical:MountingHole H2
U 1 1 5DA90ABD
P 8400 5700
F 0 "H2" H 8500 5746 50  0000 L CNN
F 1 "MountingHole" H 8250 5850 50  0000 L CNN
F 2 "MountingHole:MountingHole_3.2mm_M3" H 8400 5700 50  0001 C CNN
F 3 "~" H 8400 5700 50  0001 C CNN
	1    8400 5700
	1    0    0    -1  
$EndComp
$EndSCHEMATC
