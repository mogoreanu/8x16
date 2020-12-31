# 8x16
8x16 game based on STC15F2K60S2 - an Intel 8051 clone by STC.

The purpose of this project is to:
1. Rewrite the stock firmware with some alternative games.
1. Teach microcontroller programming on a cheap and starightforward platform

Microcontroller details:
STC15F2K60S2
28I-PDIP40
1845HVV065.XD

Microcontroller decoding:
STC The program Flash in user program area can not be used as EEPROM., but there are special EEPROM
15 STC 1T 8051 MCU, Speed is 8~12 times faster than the traditional 8051 in the same working frequency
F : Operating Voltage 5.5V~4.2V
2K SRAM: 2K = 2048 E\WHV
60 Program space, e.g. 60:60KB
S2? 2 UARTs (can be used simultaneously)' SPI' Internal EEPROM'  A/D Converter(PWM also can be used as DAC)'  CCP/PWM/PCA

28 : Up to 28MHz
I : Industrial, -40c-85c
PDIP 40

The MCU, according to the spec has the following memory:
* 2048 bytes SRAM 
* 256 byte scratch-pad RAM
* 1792 bytes of auxiliary RAM

# Hardware required

* 8x16 game

USB Serial converters tested:
* Silicon Labs CP210x 
* CH341A based programmer that is switched to USB to Serial converter mode (Jumper between pins 2 and 3)


# Development environment setup

Unfortunatelly compilers that work with Intel 8051 are scarce and the official STC documentation recommends Keil uVision. The development environment will have to be 

* Install Keil uVision C51, the version for 8051 microcontrollers. The version used in this project is V5.27.1.0. It will include the C compiler - C51 and the Intel 8051 assembly compiler A51.
* Download "STC ISP programming software (v6.86)" from http://www.stcmicro.com/rjxz.html
* Open "Keil ICE Settings" tab, Add MCU type to Keil

# Hardware tweaks

1. Capacitors at the MCU power ports. 
   The spec asks for a 47uF electrolytic and a 0.1uF ceramic capacitor at the power input of the MCU, need to add those.
1. Reroute OK and Reset buttons to empty pins to free up UART0 for programming and debug output.

Board layout

 R4+  - P00       P45 - R1+
 R6+  - P01       P27 - R3+
 R7+  - P02       P26 - C1-
 R5+  - P03       P25 - D1-
 R2+  - P04       P24 - C0-
 R8+  - P05       P23 - D0-
 R11+ - P06       P22 - C5-
 R9+  - P07       P21 - C3-
      - P10       P20 - R0+
 R14+ - P11       P44 - C2-
 R13+ - P12       P42 - C4-
 R10+ - P13       P41 - D2-
 R12+ - P14       P37 - Left
      - P15       P36 - Down
      - P16       P35 - C6-
 C7-  - P17       P34 -
 R15+ - P54       P33 - Right
 5v   - VCC       P32 - Up
 Spkr - P55       P31 - Rst
 0v   - GND       P30 - OK

 Rx - Row number x in the dot matrix display, X in [0, 15]. Rows are positive
 Cy - Column number y in the dot matrix display, Y in [0, 7]. Clumns are negative
 Dz - Digit number z, z in [0, 2]. Digit "rows" are negative, thank you.
 
 Each digit has the following layout corresponding to the dot matrix columns:
              Col 6
     Col 5              Col 0
              Col 4
     Col 2              Col 3
              Col 1
 
# Links

Stripped-down datasheet
http://www.stcmicro.com/datasheet/STC15F2K32S2_Features.pdf

Full datasheet
http://www.stcmicro.com/datasheet/STC15F2K60S2-en.pdf
https://datasheetspdf.com/pdf-file/1316710/STC/STC15F2K60S2/1

Software downloads
http://www.stcmicro.com/rjxz.html

Keil
https://www.keil.com/demo/eval/c51.htm