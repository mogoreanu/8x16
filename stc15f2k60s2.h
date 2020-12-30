#ifndef __STC15F2K60S2_H_
#define __STC15F2K60S2_H_

sfr ACC         =   0xE0;
sfr B           =   0xF0;
sfr PSW         =   0xD0;
sbit CY         =   PSW^7;
sbit AC         =   PSW^6;
sbit F0         =   PSW^5;
sbit RS1        =   PSW^4;
sbit RS0        =   PSW^3;
sbit OV         =   PSW^2;
sbit P          =   PSW^0;
sfr SP          =   0x81;
sfr DPL         =   0x82;
sfr DPH         =   0x83;

/*
Ports are bit-addressable.
    CLR     P1.0
    SETB    P1.0
    CLR     P1.1

By default the prots are econfigured in a quasi-bidirectional mode,
Other available modes:
M0    M1
0     0     quasi-bidirectional, pull up 270uA, pull down 20mA
0     1     input only, high impedance
1     0     push-pull, 20mA pull-up / pull-down
1     1     open drain, no internal pull-up, needs external pullup.
*/

sfr P0          =   0x80;
sbit P00        =   P0^0;
sbit P01        =   P0^1;
sbit P02        =   P0^2;
sbit P03        =   P0^3;
sbit P04        =   P0^4;
sbit P05        =   P0^5;
sbit P06        =   P0^6;
sbit P07        =   P0^7;
sfr P1          =   0x90;
sbit P10        =   P1^0;
sbit P11        =   P1^1;
sbit P12        =   P1^2;
sbit P13        =   P1^3;
sbit P14        =   P1^4;
sbit P15        =   P1^5;
sbit P16        =   P1^6;
sbit P17        =   P1^7;
sfr P2          =   0xA0;
sbit P20        =   P2^0;
sbit P21        =   P2^1;
sbit P22        =   P2^2;
sbit P23        =   P2^3;
sbit P24        =   P2^4;
sbit P25        =   P2^5;
sbit P26        =   P2^6;
sbit P27        =   P2^7;
sfr P3          =   0xB0;
sbit P30        =   P3^0;
sbit P31        =   P3^1;
sbit P32        =   P3^2;
sbit P33        =   P3^3;
sbit P34        =   P3^4;
sbit P35        =   P3^5;
sbit P36        =   P3^6;
sbit P37        =   P3^7;
sfr P4          =   0xC0;
sbit P40        =   P4^0;
sbit P41        =   P4^1;
sbit P42        =   P4^2;
sbit P43        =   P4^3;
sbit P44        =   P4^4;
sbit P45        =   P4^5;
sbit P46        =   P4^6;
sbit P47        =   P4^7;
sfr P5          =   0xC8;
sbit P50        =   P5^0;
sbit P51        =   P5^1;
sbit P52        =   P5^2;
sbit P53        =   P5^3;
sbit P54        =   P5^4;
sbit P55        =   P5^5;
sbit P56        =   P5^6;
sbit P57        =   P5^7;
sfr P6          =   0xE8;
sbit P60        =   P6^0;
sbit P61        =   P6^1;
sbit P62        =   P6^2;
sbit P63        =   P6^3;
sbit P64        =   P6^4;
sbit P65        =   P6^5;
sbit P66        =   P6^6;
sbit P67        =   P6^7;
sfr P7          =   0xF8;
sbit P70        =   P7^0;
sbit P71        =   P7^1;
sbit P72        =   P7^2;
sbit P73        =   P7^3;
sbit P74        =   P7^4;
sbit P75        =   P7^5;
sbit P76        =   P7^6;
sbit P77        =   P7^7;
sfr P0M0        =   0x94;
sfr P0M1        =   0x93;
sfr P1M0        =   0x92;
sfr P1M1        =   0x91;
sfr P2M0        =   0x96;
sfr P2M1        =   0x95;
sfr P3M0        =   0xB2;
sfr P3M1        =   0xB1;
sfr P4M0        =   0xB4;
sfr P4M1        =   0xB3;
sfr P5M0        =   0xCA;
sfr P5M1        =   0xC9;
sfr P6M0        =   0xCC;
sfr P6M1        =   0xCB;
sfr P7M0        =   0xE2;
sfr P7M1        =   0xE1;

sfr PCON        =   0x87;
sfr AUXR        =   0x8E;
sfr AUXR1       =   0xA2;
sfr P_SW1       =   0xA2;
sfr CLK_DIV     =   0x97;
sfr BUS_SPEED   =   0xA1;
sfr P1ASF       =   0x9D;
sfr P_SW2       =   0xBA;

sfr IE          =   0xA8;
sbit EA         =   IE^7;
sbit ELVD       =   IE^6;
sbit EADC       =   IE^5;
sbit ES         =   IE^4;
sbit ET1        =   IE^3;
sbit EX1        =   IE^2;
sbit ET0        =   IE^1;
sbit EX0        =   IE^0;
sfr IP          =   0xB8;
sbit PPCA       =   IP^7;
sbit PLVD       =   IP^6;
sbit PADC       =   IP^5;
sbit PS         =   IP^4;
sbit PT1        =   IP^3;
sbit PX1        =   IP^2;
sbit PT0        =   IP^1;
sbit PX0        =   IP^0;
sfr IE2         =   0xAF;
sfr IP2         =   0xB5;
sfr INT_CLKO    =   0x8F;

sfr TCON        =   0x88;
sbit TF1        =   TCON^7;
sbit TR1        =   TCON^6;
sbit TF0        =   TCON^5;
sbit TR0        =   TCON^4;
sbit IE1        =   TCON^3;
sbit IT1        =   TCON^2;
sbit IE0        =   TCON^1;
sbit IT0        =   TCON^0;
sfr TMOD        =   0x89;
sfr TL0         =   0x8A;
sfr TL1         =   0x8B;
sfr TH0         =   0x8C;
sfr TH1         =   0x8D;
sfr T4T3M       =   0xD1;
sfr T3T4M       =   0xD1;
sfr T4H         =   0xD2;
sfr T4L         =   0xD3;
sfr T3H         =   0xD4;
sfr T3L         =   0xD5;
sfr T2H         =   0xD6;
sfr T2L         =   0xD7;
sfr WKTCL       =   0xAA;
sfr WKTCH       =   0xAB;
sfr WDT_CONTR   =   0xC1;

sfr SCON        =   0x98;
sbit SM0        =   SCON^7;
sbit SM1        =   SCON^6;
sbit SM2        =   SCON^5;
sbit REN        =   SCON^4;
sbit TB8        =   SCON^3;
sbit RB8        =   SCON^2;
sbit TI         =   SCON^1;
sbit RI         =   SCON^0;
sfr SBUF        =   0x99;
sfr S2CON       =   0x9A;
sfr S2BUF       =   0x9B;
sfr S3CON       =   0xAC;
sfr S3BUF       =   0xAD;
sfr S4CON       =   0x84;
sfr S4BUF       =   0x85;
sfr SADDR       =   0xA9;
sfr SADEN       =   0xB9;

sfr ADC_CONTR   =   0xBC;
sfr ADC_RES     =   0xBD;
sfr ADC_RESL    =   0xBE;

sfr SPSTAT      =   0xCD;
sfr SPCTL       =   0xCE;
sfr SPDAT       =   0xCF;

sfr IAP_DATA    =   0xC2;
sfr IAP_ADDRH   =   0xC3;
sfr IAP_ADDRL   =   0xC4;
sfr IAP_CMD     =   0xC5;
sfr IAP_TRIG    =   0xC6;
sfr IAP_CONTR   =   0xC7;

sfr CCON        =   0xD8;
sbit CF         =   CCON^7;
sbit CR         =   CCON^6;
sbit CCF2       =   CCON^2;
sbit CCF1       =   CCON^1;
sbit CCF0       =   CCON^0;
sfr CMOD        =   0xD9;
sfr CL          =   0xE9;
sfr CH          =   0xF9;
sfr CCAPM0      =   0xDA;
sfr CCAPM1      =   0xDB;
sfr CCAPM2      =   0xDC;
sfr CCAP0L      =   0xEA;
sfr CCAP1L      =   0xEB;
sfr CCAP2L      =   0xEC;
sfr PCA_PWM0    =   0xF2;
sfr PCA_PWM1    =   0xF3;
sfr PCA_PWM2    =   0xF4;
sfr CCAP0H      =   0xFA;
sfr CCAP1H      =   0xFB;
sfr CCAP2H      =   0xFC;

sfr CMPCR1      =   0xE6;
sfr CMPCR2      =   0xE7;

sfr PWMCFG      =   0xf1;
sfr PWMCR       =   0xf5;
sfr PWMIF       =   0xf6;
sfr PWMFDCR     =   0xf7;

#define PWMC        (*(unsigned int  volatile xdata *)0xfff0)
#define PWMCH       (*(unsigned char volatile xdata *)0xfff0)
#define PWMCL       (*(unsigned char volatile xdata *)0xfff1)
#define PWMCKS      (*(unsigned char volatile xdata *)0xfff2)
#define PWM2T1      (*(unsigned int  volatile xdata *)0xff00)
#define PWM2T1H     (*(unsigned char volatile xdata *)0xff00)
#define PWM2T1L     (*(unsigned char volatile xdata *)0xff01)
#define PWM2T2      (*(unsigned int  volatile xdata *)0xff02)
#define PWM2T2H     (*(unsigned char volatile xdata *)0xff02)
#define PWM2T2L     (*(unsigned char volatile xdata *)0xff03)
#define PWM2CR      (*(unsigned char volatile xdata *)0xff04)
#define PWM3T1      (*(unsigned int  volatile xdata *)0xff10)
#define PWM3T1H     (*(unsigned char volatile xdata *)0xff10)
#define PWM3T1L     (*(unsigned char volatile xdata *)0xff11)
#define PWM3T2      (*(unsigned int  volatile xdata *)0xff12)
#define PWM3T2H     (*(unsigned char volatile xdata *)0xff12)
#define PWM3T2L     (*(unsigned char volatile xdata *)0xff13)
#define PWM3CR      (*(unsigned char volatile xdata *)0xff14)
#define PWM4T1      (*(unsigned int  volatile xdata *)0xff20)
#define PWM4T1H     (*(unsigned char volatile xdata *)0xff20)
#define PWM4T1L     (*(unsigned char volatile xdata *)0xff21)
#define PWM4T2      (*(unsigned int  volatile xdata *)0xff22)
#define PWM4T2H     (*(unsigned char volatile xdata *)0xff22)
#define PWM4T2L     (*(unsigned char volatile xdata *)0xff23)
#define PWM4CR      (*(unsigned char volatile xdata *)0xff24)
#define PWM5T1      (*(unsigned int  volatile xdata *)0xff30)
#define PWM5T1H     (*(unsigned char volatile xdata *)0xff30)
#define PWM5T1L     (*(unsigned char volatile xdata *)0xff31)
#define PWM5T2      (*(unsigned int  volatile xdata *)0xff32)
#define PWM5T2H     (*(unsigned char volatile xdata *)0xff32)
#define PWM5T2L     (*(unsigned char volatile xdata *)0xff33)
#define PWM5CR      (*(unsigned char volatile xdata *)0xff34)
#define PWM6T1      (*(unsigned int  volatile xdata *)0xff40)
#define PWM6T1H     (*(unsigned char volatile xdata *)0xff40)
#define PWM6T1L     (*(unsigned char volatile xdata *)0xff41)
#define PWM6T2      (*(unsigned int  volatile xdata *)0xff42)
#define PWM6T2H     (*(unsigned char volatile xdata *)0xff42)
#define PWM6T2L     (*(unsigned char volatile xdata *)0xff43)
#define PWM6CR      (*(unsigned char volatile xdata *)0xff44)
#define PWM7T1      (*(unsigned int  volatile xdata *)0xff50)        
#define PWM7T1H     (*(unsigned char volatile xdata *)0xff50)        
#define PWM7T1L     (*(unsigned char volatile xdata *)0xff51)
#define PWM7T2      (*(unsigned int  volatile xdata *)0xff52)
#define PWM7T2H     (*(unsigned char volatile xdata *)0xff52)
#define PWM7T2L     (*(unsigned char volatile xdata *)0xff53)
#define PWM7CR      (*(unsigned char volatile xdata *)0xff54)

#endif

