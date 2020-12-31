#ifndef _MY_HW_DRIVER_
#define _MY_HW_DRIVER_

#include "types.h"

enum BtnIndex {
  kDownBtn = 0,
  kUpBtn = 1,
  kLeftBtn = 2,
  kRightBtn = 3,
  kOkBtn = 4,
  kRstBtn = 5,
  kBtnCount
};

void InitHw();

void SetPixelValue(int8 row, int8 col, int8 v);
int8 GetPixelValue(int8 row, int8 col);

void SetPixel(int8 row, int8 col);
void ClearPixel(int8 row, int8 col);

int8 WasButtonPressed(int8 btn_index);

void Delay(int ms);

#endif  // _MY_HW_DRIVER_
