EESchema Schematic File Version 2
LIBS:yaacwk-rescue
LIBS:power
LIBS:device
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
LIBS:ms-conn
LIBS:w_device
LIBS:w_connectors
LIBS:yaacwk-cache
EELAYER 25 0
EELAYER END
$Descr User 11418 7481
encoding utf-8
Sheet 1 1
Title "Yet Another Arduino Cw Keyer"
Date "2016-07-05"
Rev "YAACWK AtMega 644p Rev C"
Comp "Copyright: CC BY-SA 3.0 IT by: I1cra - Iz1glg"
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Text GLabel 10700 3100 0    60   Output ~ 0
Paddles
$Comp
L HEADER_2 J1
U 1 1 54FB285A
P 1800 4800
F 0 "J1" H 1800 4950 60  0000 C CNN
F 1 "Ext PWR" H 1800 4650 60  0000 C CNN
F 2 "" H 1800 4800 60  0001 C CNN
F 3 "" H 1800 4800 60  0001 C CNN
	1    1800 4800
	-1   0    0    -1  
$EndComp
$Comp
L R-RESCUE-yaacwk R6
U 1 1 54E4FB60
P 4850 5950
F 0 "R6" V 4930 5950 40  0000 C CNN
F 1 "1k" V 4857 5951 40  0000 C CNN
F 2 "~" V 4780 5950 30  0000 C CNN
F 3 "~" H 4850 5950 30  0000 C CNN
	1    4850 5950
	-1   0    0    1   
$EndComp
$Comp
L R-RESCUE-yaacwk R7
U 1 1 54E4FB6F
P 5200 5950
F 0 "R7" V 5280 5950 40  0000 C CNN
F 1 "1k" V 5207 5951 40  0000 C CNN
F 2 "~" V 5130 5950 30  0000 C CNN
F 3 "~" H 5200 5950 30  0000 C CNN
	1    5200 5950
	-1   0    0    1   
$EndComp
$Comp
L R-RESCUE-yaacwk R8
U 1 1 54E4FB85
P 5600 5950
F 0 "R8" V 5680 5950 40  0000 C CNN
F 1 "1k" V 5607 5951 40  0000 C CNN
F 2 "~" V 5530 5950 30  0000 C CNN
F 3 "~" H 5600 5950 30  0000 C CNN
	1    5600 5950
	-1   0    0    1   
$EndComp
$Comp
L R-RESCUE-yaacwk R9
U 1 1 54E4FB94
P 7350 2000
F 0 "R9" V 7430 2000 40  0000 C CNN
F 1 "1k" V 7357 2001 40  0000 C CNN
F 2 "~" V 7280 2000 30  0000 C CNN
F 3 "~" H 7350 2000 30  0000 C CNN
	1    7350 2000
	0    -1   -1   0   
$EndComp
$Comp
L R-RESCUE-yaacwk R10
U 1 1 54E4FBA3
P 7350 2200
F 0 "R10" V 7430 2200 40  0000 C CNN
F 1 "1k" V 7357 2201 40  0000 C CNN
F 2 "~" V 7280 2200 30  0000 C CNN
F 3 "~" H 7350 2200 30  0000 C CNN
	1    7350 2200
	0    -1   -1   0   
$EndComp
$Comp
L TLP627-2-RESCUE-yaacwk IC2
U 2 1 54E4FBCB
P 8300 2650
F 0 "IC2" H 8110 2840 40  0000 C CNN
F 1 "TLP627-2" H 8400 2460 40  0000 C CNN
F 2 "DIP8" H 8100 2470 30  0000 C CIN
F 3 "~" H 8300 2650 60  0000 C CNN
	2    8300 2650
	1    0    0    -1  
$EndComp
$Comp
L TLP627-2-RESCUE-yaacwk IC2
U 1 1 54E50010
P 8300 2100
F 0 "IC2" H 8110 2290 40  0000 C CNN
F 1 "TLP627-2" H 8400 1910 40  0000 C CNN
F 2 "DIP8" H 8100 1920 30  0000 C CIN
F 3 "~" H 8300 2100 60  0000 C CNN
	1    8300 2100
	1    0    0    -1  
$EndComp
$Comp
L GND-RESCUE-yaacwk #PWR01
U 1 1 54E502DB
P 7700 2850
F 0 "#PWR01" H 7700 2850 30  0001 C CNN
F 1 "GND" H 7700 2780 30  0001 C CNN
F 2 "" H 7700 2850 60  0001 C CNN
F 3 "" H 7700 2850 60  0001 C CNN
	1    7700 2850
	1    0    0    -1  
$EndComp
$Comp
L C-RESCUE-yaacwk C4
U 1 1 54E5030E
P 9000 2100
F 0 "C4" H 9000 2200 40  0000 L CNN
F 1 "10nF" H 9006 2015 40  0000 L CNN
F 2 "~" H 9038 1950 30  0000 C CNN
F 3 "~" H 9000 2100 60  0000 C CNN
	1    9000 2100
	1    0    0    -1  
$EndComp
$Comp
L C-RESCUE-yaacwk C5
U 1 1 54E50343
P 9000 2650
F 0 "C5" H 9000 2750 40  0000 L CNN
F 1 "10nF" H 9006 2565 40  0000 L CNN
F 2 "~" H 9038 2500 30  0000 C CNN
F 3 "~" H 9000 2650 60  0000 C CNN
	1    9000 2650
	1    0    0    -1  
$EndComp
$Comp
L C-RESCUE-yaacwk C2
U 1 1 54E50416
P 8650 3500
F 0 "C2" H 8650 3600 40  0000 L CNN
F 1 "10nF" H 8656 3415 40  0000 L CNN
F 2 "~" H 8688 3350 30  0000 C CNN
F 3 "~" H 8650 3500 60  0000 C CNN
	1    8650 3500
	1    0    0    -1  
$EndComp
$Comp
L C-RESCUE-yaacwk C3
U 1 1 54E50444
P 8950 3500
F 0 "C3" H 8950 3600 40  0000 L CNN
F 1 "10nF" H 8956 3415 40  0000 L CNN
F 2 "~" H 8988 3350 30  0000 C CNN
F 3 "~" H 8950 3500 60  0000 C CNN
	1    8950 3500
	1    0    0    -1  
$EndComp
$Comp
L GND-RESCUE-yaacwk #PWR02
U 1 1 54E5054B
P 8400 3700
F 0 "#PWR02" H 8400 3700 30  0001 C CNN
F 1 "GND" H 8400 3630 30  0001 C CNN
F 2 "" H 8400 3700 60  0001 C CNN
F 3 "" H 8400 3700 60  0001 C CNN
	1    8400 3700
	0    1    1    0   
$EndComp
$Comp
L R-RESCUE-yaacwk R5
U 1 1 54E5186B
P 3250 5800
F 0 "R5" V 3330 5800 40  0000 C CNN
F 1 "1k" V 3257 5801 40  0000 C CNN
F 2 "~" V 3180 5800 30  0000 C CNN
F 3 "~" H 3250 5800 30  0000 C CNN
	1    3250 5800
	0    -1   -1   0   
$EndComp
$Comp
L R-RESCUE-yaacwk R4
U 1 1 54E5187A
P 2600 5800
F 0 "R4" V 2680 5800 40  0000 C CNN
F 1 "1k" V 2607 5801 40  0000 C CNN
F 2 "~" V 2530 5800 30  0000 C CNN
F 3 "~" H 2600 5800 30  0000 C CNN
	1    2600 5800
	0    -1   -1   0   
$EndComp
$Comp
L R-RESCUE-yaacwk R3
U 1 1 54E51889
P 2000 5800
F 0 "R3" V 2080 5800 40  0000 C CNN
F 1 "1k" V 2007 5801 40  0000 C CNN
F 2 "~" V 1930 5800 30  0000 C CNN
F 3 "~" H 2000 5800 30  0000 C CNN
	1    2000 5800
	0    -1   -1   0   
$EndComp
$Comp
L R-RESCUE-yaacwk R2
U 1 1 54E51898
P 1350 5800
F 0 "R2" V 1430 5800 40  0000 C CNN
F 1 "1k" V 1357 5801 40  0000 C CNN
F 2 "~" V 1280 5800 30  0000 C CNN
F 3 "~" H 1350 5800 30  0000 C CNN
	1    1350 5800
	0    -1   -1   0   
$EndComp
$Comp
L R-RESCUE-yaacwk R1
U 1 1 54E518B6
P 850 5800
F 0 "R1" V 930 5800 40  0000 C CNN
F 1 "10k" V 857 5801 40  0000 C CNN
F 2 "~" V 780 5800 30  0000 C CNN
F 3 "~" H 850 5800 30  0000 C CNN
	1    850  5800
	0    -1   -1   0   
$EndComp
$Comp
L GND-RESCUE-yaacwk #PWR03
U 1 1 54E51BAC
P 5400 6900
F 0 "#PWR03" H 5400 6900 30  0001 C CNN
F 1 "GND" H 5400 6830 30  0001 C CNN
F 2 "" H 5400 6900 60  0001 C CNN
F 3 "" H 5400 6900 60  0001 C CNN
	1    5400 6900
	1    0    0    -1  
$EndComp
$Comp
L SW_PUSH SW5
U 1 1 54E51BF5
P 3500 6500
F 0 "SW5" H 3650 6610 50  0000 C CNN
F 1 "SW_PUSH" H 3500 6420 50  0000 C CNN
F 2 "~" H 3500 6500 60  0000 C CNN
F 3 "~" H 3500 6500 60  0000 C CNN
	1    3500 6500
	0    -1   -1   0   
$EndComp
$Comp
L SW_PUSH SW4
U 1 1 54E51BFB
P 2850 6500
F 0 "SW4" H 3000 6610 50  0000 C CNN
F 1 "SW_PUSH" H 2850 6420 50  0000 C CNN
F 2 "~" H 2850 6500 60  0000 C CNN
F 3 "~" H 2850 6500 60  0000 C CNN
	1    2850 6500
	0    -1   -1   0   
$EndComp
$Comp
L SW_PUSH SW3
U 1 1 54E51C21
P 2250 6500
F 0 "SW3" H 2400 6610 50  0000 C CNN
F 1 "SW_PUSH" H 2250 6420 50  0000 C CNN
F 2 "~" H 2250 6500 60  0000 C CNN
F 3 "~" H 2250 6500 60  0000 C CNN
	1    2250 6500
	0    -1   -1   0   
$EndComp
$Comp
L SW_PUSH SW2
U 1 1 54E51C30
P 1600 6500
F 0 "SW2" H 1750 6610 50  0000 C CNN
F 1 "SW_PUSH" H 1600 6420 50  0000 C CNN
F 2 "~" H 1600 6500 60  0000 C CNN
F 3 "~" H 1600 6500 60  0000 C CNN
	1    1600 6500
	0    -1   -1   0   
$EndComp
$Comp
L SW_PUSH SW1
U 1 1 54E51C3F
P 1100 6500
F 0 "SW1" H 1250 6610 50  0000 C CNN
F 1 "SW_PUSH" H 1100 6420 50  0000 C CNN
F 2 "~" H 1100 6500 60  0000 C CNN
F 3 "~" H 1100 6500 60  0000 C CNN
	1    1100 6500
	0    -1   -1   0   
$EndComp
$Comp
L POT-RESCUE-yaacwk SpeedPot1
U 1 1 54E782C2
P 4200 6600
F 0 "SpeedPot1" H 4200 6500 50  0000 C CNN
F 1 "10k" H 4200 6600 50  0000 C CNN
F 2 "~" H 4200 6600 60  0000 C CNN
F 3 "~" H 4200 6600 60  0000 C CNN
	1    4200 6600
	1    0    0    -1  
$EndComp
$Comp
L LED-RESCUE-yaacwk D2
U 1 1 54E78476
P 5200 6400
F 0 "D2" H 5200 6500 50  0000 C CNN
F 1 "LED" H 5200 6300 50  0000 C CNN
F 2 "~" H 5200 6400 60  0000 C CNN
F 3 "~" H 5200 6400 60  0000 C CNN
	1    5200 6400
	0    1    1    0   
$EndComp
$Comp
L LED-RESCUE-yaacwk D3
U 1 1 54E78485
P 5600 6400
F 0 "D3" H 5600 6500 50  0000 C CNN
F 1 "LED" H 5600 6300 50  0000 C CNN
F 2 "~" H 5600 6400 60  0000 C CNN
F 3 "~" H 5600 6400 60  0000 C CNN
	1    5600 6400
	0    1    1    0   
$EndComp
$Comp
L LED-RESCUE-yaacwk D1
U 1 1 54E78494
P 4850 6400
F 0 "D1" H 4850 6500 50  0000 C CNN
F 1 "LED" H 4850 6300 50  0000 C CNN
F 2 "~" H 4850 6400 60  0000 C CNN
F 3 "~" H 4850 6400 60  0000 C CNN
	1    4850 6400
	0    1    1    0   
$EndComp
$Comp
L INDUCTOR L2
U 1 1 54E9B16A
P 9100 1800
F 0 "L2" V 9050 1800 40  0000 C CNN
F 1 "INDUCTOR 5μH" V 9200 1800 40  0000 C CNN
F 2 "~" H 9100 1800 60  0000 C CNN
F 3 "~" H 9100 1800 60  0000 C CNN
	1    9100 1800
	0    -1   -1   0   
$EndComp
$Comp
L INDUCTOR L1
U 1 1 54E9B179
P 9000 650
F 0 "L1" V 8950 650 40  0000 C CNN
F 1 "INDUCTOR 5μH" V 9100 650 40  0000 C CNN
F 2 "~" H 9000 650 60  0000 C CNN
F 3 "~" H 9000 650 60  0000 C CNN
	1    9000 650 
	0    -1   -1   0   
$EndComp
$Comp
L miniDIN6 CONN1
U 1 1 54E9BF6C
P 9850 1300
F 0 "CONN1" H 9850 1700 60  0000 C CNN
F 1 "MINIDIN6" H 9850 1300 31  0000 C CNN
F 2 "" H 9850 1300 60  0001 C CNN
F 3 "" H 9850 1300 60  0001 C CNN
	1    9850 1300
	1    0    0    -1  
$EndComp
$Comp
L HEADER_2 J3
U 1 1 54E9C5D5
P 10050 2050
F 0 "J3" H 10050 2200 60  0000 C CNN
F 1 "TX PTT" H 10050 1900 60  0000 C CNN
F 2 "" H 10050 2050 60  0001 C CNN
F 3 "" H 10050 2050 60  0001 C CNN
	1    10050 2050
	1    0    0    -1  
$EndComp
$Comp
L HEADER_2 J2
U 1 1 54E9C5E4
P 10050 2500
F 0 "J2" H 10050 2650 60  0000 C CNN
F 1 "TX Key" H 10050 2350 60  0000 C CNN
F 2 "" H 10050 2500 60  0001 C CNN
F 3 "" H 10050 2500 60  0001 C CNN
	1    10050 2500
	1    0    0    -1  
$EndComp
$Comp
L buzzer BZ1
U 1 1 54E9D208
P 6750 2500
F 0 "BZ1" H 6825 2550 50  0000 L CNN
F 1 "BUZZER" H 6825 2450 50  0000 L CNN
F 2 "" H 6750 2500 60  0001 C CNN
F 3 "" H 6750 2500 60  0001 C CNN
	1    6750 2500
	-1   0    0    1   
$EndComp
$Comp
L GND-RESCUE-yaacwk #PWR05
U 1 1 54E9D314
P 10500 1600
F 0 "#PWR05" H 10500 1600 30  0001 C CNN
F 1 "GND" H 10500 1530 30  0001 C CNN
F 2 "" H 10500 1600 60  0001 C CNN
F 3 "" H 10500 1600 60  0001 C CNN
	1    10500 1600
	1    0    0    -1  
$EndComp
$Comp
L 3.5"_STEREO_JACK CONN2
U 1 1 54EFB354
P 9850 3100
F 0 "CONN2" H 9700 3250 60  0000 C CNN
F 1 "3.5\"_STEREO_JACK" H 9900 2850 60  0000 C CNN
F 2 "" H 9850 3100 60  0001 C CNN
F 3 "" H 9850 3100 60  0001 C CNN
	1    9850 3100
	-1   0    0    -1  
$EndComp
Text GLabel 1550 4850 0    31   Input ~ 0
 5V 
Text GLabel 1550 4750 0    31   Input ~ 0
GND
$Comp
L C-RESCUE-yaacwk C1
U 1 1 55D9E040
P 4400 6150
F 0 "C1" H 4400 6250 40  0000 L CNN
F 1 "5nF" H 4406 6065 40  0000 L CNN
F 2 "~" H 4438 6000 30  0000 C CNN
F 3 "~" H 4400 6150 60  0000 C CNN
	1    4400 6150
	0    -1   -1   0   
$EndComp
$Comp
L C-RESCUE-yaacwk C9
U 1 1 56946CCB
P 3750 6450
F 0 "C9" H 3750 6550 40  0000 L CNN
F 1 "100nF" H 3756 6365 40  0000 L CNN
F 2 "~" H 3788 6300 30  0000 C CNN
F 3 "~" H 3750 6450 60  0000 C CNN
	1    3750 6450
	-1   0    0    1   
$EndComp
$Comp
L C-RESCUE-yaacwk C8
U 1 1 56946CE6
P 3050 6450
F 0 "C8" H 3050 6550 40  0000 L CNN
F 1 "100nF" H 3056 6365 40  0000 L CNN
F 2 "~" H 3088 6300 30  0000 C CNN
F 3 "~" H 3050 6450 60  0000 C CNN
	1    3050 6450
	-1   0    0    1   
$EndComp
$Comp
L C-RESCUE-yaacwk C7
U 1 1 56946CEC
P 2450 6450
F 0 "C7" H 2450 6550 40  0000 L CNN
F 1 "100nF" H 2456 6365 40  0000 L CNN
F 2 "~" H 2488 6300 30  0000 C CNN
F 3 "~" H 2450 6450 60  0000 C CNN
	1    2450 6450
	-1   0    0    1   
$EndComp
$Comp
L C-RESCUE-yaacwk C6
U 1 1 56946CF2
P 1850 6450
F 0 "C6" H 1850 6550 40  0000 L CNN
F 1 "100nF" H 1856 6365 40  0000 L CNN
F 2 "~" H 1888 6300 30  0000 C CNN
F 3 "~" H 1850 6450 60  0000 C CNN
	1    1850 6450
	-1   0    0    1   
$EndComp
$Comp
L ATMEGA644P-P IC?
U 1 1 57203D81
P 3050 3200
F 0 "IC?" H 2200 5080 50  0000 L BNN
F 1 "ATMEGA644P-P" H 3450 1250 50  0000 L BNN
F 2 "DIL40" H 3050 3200 50  0000 C CIN
F 3 "" H 3050 3200 50  0000 C CNN
	1    3050 3200
	1    0    0    -1  
$EndComp
$Comp
L GND-RESCUE-yaacwk #PWR?
U 1 1 5726A192
P 1650 1300
F 0 "#PWR?" H 1650 1300 30  0001 C CNN
F 1 "GND" H 1650 1230 30  0001 C CNN
F 2 "" H 1650 1300 60  0001 C CNN
F 3 "" H 1650 1300 60  0001 C CNN
	1    1650 1300
	-1   0    0    1   
$EndComp
$Comp
L Crystal Y?
U 1 1 5726AF8E
P 1650 1900
F 0 "Y?" H 1650 2050 50  0000 C CNN
F 1 "Crystal" H 1650 1750 50  0000 C CNN
F 2 "" H 1650 1900 50  0000 C CNN
F 3 "" H 1650 1900 50  0000 C CNN
	1    1650 1900
	1    0    0    -1  
$EndComp
$Comp
L C C?
U 1 1 5726B6CB
P 1450 1550
F 0 "C?" H 1475 1650 50  0000 L CNN
F 1 "C" H 1475 1450 50  0000 L CNN
F 2 "" H 1488 1400 50  0000 C CNN
F 3 "" H 1450 1550 50  0000 C CNN
	1    1450 1550
	1    0    0    -1  
$EndComp
$Comp
L C C?
U 1 1 5726B75C
P 1850 1550
F 0 "C?" H 1875 1650 50  0000 L CNN
F 1 "C" H 1875 1450 50  0000 L CNN
F 2 "" H 1888 1400 50  0000 C CNN
F 3 "" H 1850 1550 50  0000 C CNN
	1    1850 1550
	1    0    0    -1  
$EndComp
$Comp
L LCD16X2 DS?
U 1 1 5723DD97
P 9700 4650
F 0 "DS?" H 8900 5050 50  0000 C CNN
F 1 "LCD16X2" H 10400 5050 50  0000 C CNN
F 2 "WC1602A" H 9700 4600 50  0000 C CIN
F 3 "" H 9700 4650 50  0000 C CNN
	1    9700 4650
	0    1    1    0   
$EndComp
$Comp
L C C10
U 1 1 5726A520
P 5700 1350
F 0 "C10" H 5725 1450 50  0000 L CNN
F 1 "C 100nF" H 5725 1250 50  0000 L CNN
F 2 "" H 5738 1200 50  0000 C CNN
F 3 "" H 5700 1350 50  0000 C CNN
	1    5700 1350
	0    1    1    0   
$EndComp
$Comp
L Jack_3.5mm_3pin J?
U 1 1 5726DF4D
P 6400 6550
F 0 "J?" H 6400 6800 60  0000 C CNN
F 1 "Jack_3.5mm_3pin" H 6400 6300 60  0000 C CNN
F 2 "" H 6400 6550 60  0000 C CNN
F 3 "" H 6400 6550 60  0000 C CNN
	1    6400 6550
	0    1    1    0   
$EndComp
$Comp
L R-RESCUE-yaacwk R?
U 1 1 57246EE4
P 5400 1100
F 0 "R?" V 5480 1100 40  0000 C CNN
F 1 "10k" V 5407 1101 40  0000 C CNN
F 2 "~" V 5330 1100 30  0000 C CNN
F 3 "~" H 5400 1100 30  0000 C CNN
	1    5400 1100
	1    0    0    -1  
$EndComp
$Comp
L R-RESCUE-yaacwk R?
U 1 1 57247C48
P 5400 1600
F 0 "R?" V 5480 1600 40  0000 C CNN
F 1 "10k" V 5407 1601 40  0000 C CNN
F 2 "~" V 5330 1600 30  0000 C CNN
F 3 "~" H 5400 1600 30  0000 C CNN
	1    5400 1600
	1    0    0    -1  
$EndComp
$Comp
L POT-RESCUE-yaacwk LightPot
U 1 1 57261201
P 7550 3750
F 0 "LightPot" H 7550 3650 50  0000 C CNN
F 1 "10k" H 7550 3750 50  0000 C CNN
F 2 "~" H 7550 3750 60  0000 C CNN
F 3 "~" H 7550 3750 60  0000 C CNN
	1    7550 3750
	1    0    0    -1  
$EndComp
$Comp
L R-RESCUE-yaacwk R9
U 1 1 577B7C13
P 5900 6500
F 0 "R9" V 5980 6500 40  0000 C CNN
F 1 "220Ω" V 5907 6501 40  0000 C CNN
F 2 "~" V 5830 6500 30  0000 C CNN
F 3 "~" H 5900 6500 30  0000 C CNN
	1    5900 6500
	1    0    0    -1  
$EndComp
$Comp
L LED-RESCUE-yaacwk D4
U 1 1 577B7C19
P 5900 6050
F 0 "D4" H 5900 6150 50  0000 C CNN
F 1 "LED" H 5900 5950 50  0000 C CNN
F 2 "~" H 5900 6050 60  0000 C CNN
F 3 "~" H 5900 6050 60  0000 C CNN
	1    5900 6050
	0    -1   -1   0   
$EndComp
Wire Wire Line
	6150 4300 6150 5200
Wire Wire Line
	6450 4200 6450 5100
Wire Wire Line
	6600 3900 6600 4200
Wire Wire Line
	6250 1350 6250 6400
Wire Wire Line
	4750 2700 4750 3000
Wire Wire Line
	4050 2600 4600 2600
Connection ~ 7300 3750
Wire Wire Line
	7300 3750 7300 4000
Wire Wire Line
	8050 3750 7800 3750
Connection ~ 8050 3900
Wire Wire Line
	7550 3450 8250 3450
Wire Wire Line
	7550 3600 7550 3450
Connection ~ 3000 5300
Connection ~ 3100 5300
Connection ~ 5400 5300
Wire Wire Line
	9250 1900 9250 2000
Wire Wire Line
	9250 2000 9950 2000
Connection ~ 9800 2300
Wire Wire Line
	9950 2100 9800 2100
Wire Wire Line
	5850 1350 6250 1350
Connection ~ 8650 3700
Connection ~ 5400 6800
Wire Wire Line
	5600 6800 5600 6600
Connection ~ 5200 6800
Wire Wire Line
	5200 6800 5200 6600
Connection ~ 4600 6800
Connection ~ 4850 6800
Wire Wire Line
	4850 6800 4850 6600
Connection ~ 3900 5600
Wire Wire Line
	600  5600 600  5800
Wire Wire Line
	4450 5450 1100 5450
Wire Wire Line
	4450 1600 4450 5450
Wire Wire Line
	4450 1600 4050 1600
Connection ~ 4850 5600
Wire Wire Line
	600  5600 4850 5600
Wire Wire Line
	1600 5800 1600 6200
Wire Wire Line
	2250 5800 2250 6200
Wire Wire Line
	2850 5800 2850 6200
Wire Wire Line
	3500 5800 3500 6200
Wire Wire Line
	2000 5100 1250 5100
Wire Wire Line
	2000 4850 2000 5100
Wire Wire Line
	1900 4850 2000 4850
Wire Wire Line
	2100 4750 2100 5300
Wire Wire Line
	1900 4750 2100 4750
Wire Wire Line
	7300 2450 7300 2750
Wire Wire Line
	6800 2450 7300 2450
Wire Wire Line
	7600 2550 7600 2200
Wire Wire Line
	7100 2200 5200 2200
Wire Wire Line
	7100 2000 5600 2000
Wire Wire Line
	5200 2000 5200 1350
Wire Wire Line
	4050 2000 5200 2000
Connection ~ 8050 4800
Wire Wire Line
	9200 4800 8050 4800
Wire Wire Line
	6150 5200 9200 5200
Wire Wire Line
	4050 4300 6150 4300
Wire Wire Line
	6450 5100 9200 5100
Wire Wire Line
	4050 4200 6450 4200
Wire Wire Line
	4300 5000 9200 5000
Wire Wire Line
	4300 3100 4300 5000
Wire Wire Line
	4050 3100 4300 3100
Wire Wire Line
	4550 4900 9200 4900
Wire Wire Line
	4550 3000 4550 4900
Wire Wire Line
	4050 3000 4550 3000
Wire Wire Line
	4050 4400 9200 4400
Wire Wire Line
	4050 1800 8800 1800
Wire Wire Line
	6600 4200 9200 4200
Wire Wire Line
	4350 3900 6600 3900
Wire Wire Line
	4350 1700 4350 3900
Wire Wire Line
	4050 1700 4350 1700
Connection ~ 8050 4300
Wire Wire Line
	8250 3450 8250 4100
Wire Wire Line
	8250 4100 9200 4100
Wire Wire Line
	8050 3750 8050 5400
Connection ~ 5400 800 
Wire Wire Line
	5400 800  5400 850 
Wire Wire Line
	8050 4300 9200 4300
Wire Wire Line
	4650 2900 4650 3200
Wire Wire Line
	7300 4000 9200 4000
Wire Wire Line
	5000 3750 7300 3750
Wire Wire Line
	8050 3900 9200 3900
Connection ~ 8950 3700
Connection ~ 8650 3000
Connection ~ 8950 3200
Wire Wire Line
	8950 3300 8950 3200
Wire Wire Line
	8650 3300 8650 3000
Connection ~ 5400 1350
Wire Wire Line
	5200 1350 5550 1350
Wire Wire Line
	9400 1800 10350 1800
Wire Wire Line
	10350 1800 10350 1500
Wire Wire Line
	9050 800  9050 1300
Wire Wire Line
	9050 1300 9200 1300
Connection ~ 5000 800 
Wire Wire Line
	5000 800  5000 3750
Wire Wire Line
	4050 2900 4650 2900
Wire Wire Line
	4600 2600 4600 650 
Wire Wire Line
	4050 2700 4750 2700
Wire Wire Line
	5600 2000 5600 5700
Wire Wire Line
	7600 2000 7950 2000
Connection ~ 4850 800 
Wire Wire Line
	5400 1850 5400 6900
Wire Wire Line
	4600 6800 4600 6150
Wire Wire Line
	3000 5200 3000 5300
Connection ~ 1650 1400
Wire Wire Line
	1650 1300 1650 1400
Wire Wire Line
	1450 1400 1850 1400
Connection ~ 1850 1900
Wire Wire Line
	1850 1700 1850 1900
Connection ~ 1450 1900
Wire Wire Line
	1500 1900 1450 1900
Wire Wire Line
	1450 1700 1450 2300
Wire Wire Line
	1450 2300 2050 2300
Wire Wire Line
	1800 1900 2050 1900
Wire Wire Line
	9250 3700 9250 3300
Wire Wire Line
	1100 6800 5900 6800
Wire Wire Line
	4450 6600 4600 6600
Connection ~ 2900 800 
Wire Wire Line
	1250 5100 1250 800 
Connection ~ 5200 4500
Wire Wire Line
	4050 4500 5200 4500
Connection ~ 5600 4600
Wire Wire Line
	5600 4600 4050 4600
Wire Wire Line
	6800 2800 4050 2800
Wire Wire Line
	4600 650  8700 650 
Wire Wire Line
	1100 5450 1100 6200
Wire Wire Line
	2100 5300 8050 5300
Wire Wire Line
	3100 5300 3100 5200
Connection ~ 3200 800 
Wire Wire Line
	3200 800  3200 1200
Wire Wire Line
	2900 800  2900 1200
Wire Wire Line
	1250 800  9050 800 
Wire Wire Line
	4200 1500 4050 1500
Wire Wire Line
	4200 1500 4200 6450
Wire Wire Line
	3900 5600 3900 6600
Connection ~ 1100 6200
Connection ~ 3500 6200
Connection ~ 2850 6200
Connection ~ 1600 6200
Connection ~ 2250 6200
Connection ~ 1600 5800
Connection ~ 2250 5800
Connection ~ 2850 5800
Wire Wire Line
	1850 6650 1600 6650
Wire Wire Line
	1600 6200 1850 6250
Wire Wire Line
	2250 6200 2450 6250
Wire Wire Line
	2450 6650 2250 6650
Wire Wire Line
	2850 6200 3050 6250
Wire Wire Line
	3050 6650 2850 6650
Wire Wire Line
	3500 6200 3750 6250
Wire Wire Line
	3750 6650 3500 6650
Wire Wire Line
	9250 3300 9450 3300
Wire Wire Line
	6800 2550 6800 2800
Wire Wire Line
	4650 3200 9450 3200
Wire Wire Line
	10400 650  9300 650 
Wire Wire Line
	10400 650  10400 1100
Wire Wire Line
	7600 2550 7950 2550
Wire Wire Line
	8850 2300 9800 2300
Wire Wire Line
	8850 1900 9250 1900
Wire Wire Line
	8400 3700 9250 3700
Wire Wire Line
	10500 1600 10500 1300
Connection ~ 9000 2300
Connection ~ 9400 2300
Wire Wire Line
	8800 2850 9400 2850
Wire Wire Line
	8800 2750 8800 2850
Wire Wire Line
	8650 2750 8800 2750
Wire Wire Line
	8800 2550 8800 2450
Wire Wire Line
	8650 2550 8800 2550
Wire Wire Line
	8850 2200 8850 2300
Wire Wire Line
	8650 2200 8850 2200
Wire Wire Line
	8850 2000 8850 1900
Wire Wire Line
	8650 2000 8850 2000
Wire Wire Line
	7700 2200 7950 2200
Wire Wire Line
	9400 2850 9400 2300
Connection ~ 9000 2850
Connection ~ 9000 1900
Connection ~ 9000 2450
Wire Wire Line
	3000 5800 2850 5800
Connection ~ 1100 5800
Connection ~ 1600 6800
Connection ~ 2250 6800
Connection ~ 2850 6800
Connection ~ 3500 6800
Wire Wire Line
	1750 5800 1600 5800
Wire Wire Line
	3900 6600 3950 6600
Connection ~ 4200 6150
Connection ~ 1100 6800
Connection ~ 4600 6600
Wire Wire Line
	2200 5000 2200 4500
Wire Wire Line
	4850 800  4850 5700
Wire Wire Line
	9800 2550 9950 2550
Wire Wire Line
	9800 2100 9800 2550
Wire Wire Line
	8800 2450 9950 2450
Wire Wire Line
	7700 2200 7700 2850
Connection ~ 7700 2750
Wire Wire Line
	4750 3000 9450 3000
Wire Wire Line
	2350 5800 2250 5800
Wire Wire Line
	7300 2750 7950 2750
Wire Wire Line
	5200 2200 5200 5700
Wire Wire Line
	6450 6250 6250 6250
Wire Wire Line
	5900 6800 5900 6750
Connection ~ 5600 6800
Wire Wire Line
	5900 5850 5900 2100
Wire Wire Line
	5900 2100 4050 2100
Wire Wire Line
	8050 5400 9200 5400
Connection ~ 8050 5300
Wire Wire Line
	9200 5300 8150 5300
Wire Wire Line
	8150 5300 8150 4000
Connection ~ 8150 4000
$EndSCHEMATC
