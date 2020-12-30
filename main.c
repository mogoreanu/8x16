#include "stc15f2k60s2.h"
#include "types.h"

int col = 0;
uint8 d[17][5];

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

// Designed to run at 27.000MHz
void Delay10ms() {
  unsigned char i, j, k;

  i = 1;
  j = 15;
  k = 44;
  do {
    do {
      while (--k) {};
    } while (--j);
  } while (--i);
}

void Delay30ms() {
  unsigned char i, j, k;

  i = 1;
  j = 45;
  k = 44;
  do {
    do {
      while (--k) {};
    } while (--j);
  } while (--i);
}

void Delay1000ms() {
  unsigned char i, j, k;

  i = 103; // 1 sec
  j = 153;
  k = 44;
  do {
    do {
      while (--k) {};
    } while (--j);
  } while (--i);
}

void Delay500ms() {
  unsigned char i, j, k;

  i = 51;
  j = 153;
  k = 44;
  do {
    do {
      while (--k) {};
    } while (--j);
  } while (--i);
}

void Delay250ms() {
  unsigned char i, j, k;

  i = 25;
  j = 153;
  k = 44;
  do {
    do {
      while (--k) {};
    } while (--j);
  } while (--i);
}

void SetRow(int row, int v) {
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

void SetCol(int col, int v) {
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

void Sleep1s() {
  Delay1000ms();
  /*
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
  */
}

void Init() {
  int8 i, j;

  OffAll();
  col = 0;
  // SetRow(row, 1);
  SetCol(col, 1);
  // Set the rows to have push-pull mode, 20ma
  P0M0 = 0xFF;
  P1M0 = 0x1E;
  P2M0 = 0x81;
  P4M0 = 0x20;
  P5M0 = 0x10;

  // Drive buttons up.
  P30 = 1;  // OK
  P31 = 1;  // Reset
  P32 = 1;  // Up
  P33 = 1;  // Right
  P36 = 1;  // Down
  P37 = 1;  // Left

  for (i = 0; i < 16; ++i) {
    for (j = 0; j < 5; ++j) {
      d[i][j] = 0;
    }
  }

  // Use Timer 0 in 16-bit Timer operating mode  
  TMOD = 0x01;    
}

void ResetTimer0(void) {
  TH0 = 0xEF;
  TL0 = 0xCD;         // Set to 4.5 milliseconds  
}

void ConfigureTimer0(void) {
  ResetTimer0();          // Load timer0 start value
  TR0 = 1;                // Start Timer 0
  ET0 = 1;                // Enable Timer 0 overflow interrupt
}

void EnableInterrupt(void) {
  EA = 1;
}

void Display() {
  int8 i;

 // Turn OFF whatever columns was ON.
  SetCol(col, 1);

  // Turn off all the rows.
  for (i = 0; i < 16; ++i) {
    SetRow(i, 0);
  }
  ++col;
  if (col == 5) { 
    col = 0; 
  }

  for (i = 0; i < 16; ++i) {
    if (d[i][col] == 1) {
      SetRow(i, 1);
    }
  }
	
  // Turn ON col.
  SetCol(col, 0);	
}

void main(void) {
  int8 i, j;

  Init();  // Set timer0 in 16 bit mode.
  ConfigureTimer0();  // Load the value, start and enable "function call" when overflow
  EnableInterrupt();  // Enable

  d[0][1] = 1;
  d[0][2] = 1;
  d[0][3] = 1;

  d[1][0] = 1;
  d[1][4] = 1;

  d[2][0] = 1;
  d[2][4] = 1;

  d[3][0] = 1;
  d[3][4] = 1;

  d[5][1] = 1;
  d[5][2] = 1;
  d[5][3] = 1;

  d[6][0] = 1;
  d[6][4] = 1;

  d[7][0] = 1;
  d[7][4] = 1;

  d[8][1] = 1;
  d[8][2] = 1;
  d[8][3] = 1;

  d[10][0] = 1;
  d[10][1] = 1;
  d[10][2] = 1;
  d[10][3] = 1;
  d[10][4] = 1; // Causes the MCU to crash.

  d[11][3] = 1;

  d[12][2] = 1;

  d[13][0] = 1;
  d[13][1] = 1;
  d[13][2] = 1;
  d[13][3] = 1;
  d[13][4] = 1;

  while (1) {
    for (j = 0; j < 5; ++j) {
      d[16][j] = d[0][j];
    }
    for (i = 0; i < 16; ++i) {
      for (j = 0; j < 5; ++j) {
        d[i][j] = d[i + 1][j];
      }
    }
    
    
    Delay250ms();

    // Turn on col 0
    
    // Turn off
    // SetRow(row, 0);
    // SetCol(col, 1);
    // Move
    // NextRow();
    // NextCol();
    
    // Turn on
    // SetRow(row, 1);
    // SetCol(col, 0);
  }
}

// Runs each time timer 0 interrupt is generated 
void MyFunc() interrupt 1 {
  Display();
  ResetTimer0();
}
