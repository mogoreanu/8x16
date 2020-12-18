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

# Hardware required

* 8x16 game

USB Serial converters tested:
* Silicon Labs CP210x 
* CH341A based programmer that is switched to USB to Serial converter mode (Jumper between pins 2 and 3)


# Development environment setup

Unfortunatelly compilers that work with Intel 8051 are scarce and the official STC documentation recommends Keil uVision

* Install Keil uVision V5.27.1.0 or later for Intel 8051. It will include the C compiler - C51 and the Intel 8051 assembly compiler A51.
* Download "STC ISP programming software (v6.86)" from http://www.stcmicro.com/rjxz.html
* Open "Keil ICE Settings" tab, Add MCU type to Keil

# Links

Stripped-down datasheet
http://www.stcmicro.com/datasheet/STC15F2K32S2_Features.pdf

Full datasheet
http://www.stcmicro.com/datasheet/STC15F2K60S2-en.pdf
https://datasheetspdf.com/pdf-file/1316710/STC/STC15F2K60S2/1

Software downloads
http://www.stcmicro.com/rjxz.html

