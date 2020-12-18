// #include <REG51.H>
#include "stc15f2k60s2.h"
#include "types.h"

/*
M0    M1
0     0     quasi-bidirectional, pull up 270uA, pull down 20mA
0     1     input only, high impedance
1     0     push-pull, 20mA pull-up / pull-down
1     1     open drain, no internal pull-up, needs external pullup.

Ports are bit-addressable.
    CLR     P1.0
    SETB    P1.0
    CLR     P1.1

DELAY:
    MOV     R0,#20
    MOV     R1,#0
    MOV     R2,#0
DELAY1:
    DJNZ    R2,DELAY1
    DJNZ    R1,DELAY1
    DJNZ    R0,DELAY1
    RET
*/

volatile long i;

void OffAll() {
	P0 = 0;
	P1 = 0x80;
	P2 = 0x7E;
	P3 = 0x20;
	P4 = 0x16;
	P5 = 0;
}

void OffCols() {
	P24 = 1;  // Col 1
	P26 = 1;  // Col 2
	P44 = 1;  // Col 3
	P21 = 1;  // Col 4
	P42 = 1;  // Col 5
	P22 = 1;  // Col 6
	P35 = 1;  // Col 7
	P17 = 1;  // Col 8
}

void Delay1000ms()		//@27.000MHz
{
	unsigned char i, j, k;

	// i = 103; // 1 sec
	i = 10;
	j = 153;
	k = 44;
	do {
		do {
			while (--k) {};
		} while (--j);
	} while (--i);
}

int row = 0;
int col = 0;

void SetRow(int v) {
	switch (row) {
		case 0: P20 = v; break;
		case 1: P45 = v; break;
		case 2: P04 = v; break;
		case 3: P27 = v; break;
		case 4: P00 = v; break;
		case 5: P03 = v; break;
		case 6: P01 = v; break;
		case 7: P02 = v; break;
		case 8: P05 = v; break;
		case 9: P07 = v; break;
		case 10: P13 = v; break;
		case 11: P06 = v; break;
		case 12: P14 = v; break;
		case 13: P12 = v; break;
		case 14: P11 = v; break;
		case 15: P54 = v; break;

		// The digits have to be driven in reverse.
		case 16: P23 = v; break;
		case 17: P25 = v; break;
		case 18: P41 = v; break;
	}
}

void SetCol(int v) {
	switch (col) {
		case 0: P24 = v; break;
		case 1: P26 = v; break;
		case 2: P44 = v; break;
		case 3: P21 = v; break;
		case 4: P42 = v; break;
		case 5: P22 = v; break;
		case 6: P35 = v; break;
		case 7: P17 = v; break;
	}
}

void NextRow() {
	SetRow(0);
	++row;
	if (row == 16) { row = 0; }
	SetRow(1);
}

void PrevRow() {
	SetRow(0);
	if (row == 0) { 
		row = 15; 
  } else {
	  --row;
	}
	SetRow(1);
}

void NextCol() {
	SetCol(1);
	++col;
	if (col == 8) { col = 0; }
	SetCol(0);
}

void PrevCol() {
	SetCol(1);
	if (col == 0) { col = 7; }
	else { --col; }
	SetCol(0);
}

void Sleep1s() {
	Delay1000ms();
	if (P36 == 0) {  // Down
		NextRow();
	}
	if (P32 == 0) {  // Up
		PrevRow();
	}
	if (P33 == 0) {  // Right
		NextCol();
	}
	if (P37 == 0) {  // Left
		PrevCol();
	}
}

void main(void) {
  OffAll();
	row = 2;
	col = 5;
	SetRow(1);
	SetCol(0);
	
	// Drive buttons up.
	P30 = 1;  // OK
	P31 = 1;  // Reset
	P32 = 1;  // Up
	P33 = 1;  // Right
	P36 = 1;  // Down
	P37 = 1;  // Left
	
  while (1) {
		// P24 = 0;  // Col 1
		// Sleep1s(); 
		// P26 = 0;  // Col 2
		// Sleep1s();
		// P44 = 0;  // Col 3
		// Sleep1s();
		// P21 = 0;  // Col 4
		// Sleep1s();
		// P42 = 0;  // Col 5
		// Sleep1s();
		// P22 = 0;  // Col 6
		// Sleep1s();
		// P35 = 0;  // Col 7
		// Sleep1s();
		// P17 = 0;  // Col 8
		Sleep1s();
    //OffCols();
  }
}


