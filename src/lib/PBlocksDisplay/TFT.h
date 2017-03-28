//
// Created by indrek on 26.03.2017.
//

#ifndef PBLOCKMAIN_TFT_H
#define PBLOCKMAIN_TFT_H


#include <MCUFRIEND_kbv.h>
#include "utility/mcufriend_shield.h"
#include "IconBuffer.h"


class TFT : public MCUFRIEND_kbv {

private:
    // _MW is private in MCUFRIEND_kbv.h
    uint16_t _MW = 0x2C;

public:
    void drawIcon(uint16_t x, uint16_t y, IconBuffer & icon, uint8_t w, uint8_t h, uint8_t scale);


private:
    inline void writeColorN(RgbColor color, uint16_t n) __attribute__((always_inline));
    inline void write8bitmap(
        RgbColor color,
        RgbColor bgColor,
        uint16_t bitmap,
        uint8_t scale) __attribute__((always_inline));


    inline void write8bitmapWithBorder(
        RgbColor color,
        RgbColor bgColor,
        RgbColor bColor,
        uint16_t prvBitmap,
        uint16_t curBitmap,
        uint16_t nxtBitmap,
        uint8_t scale) __attribute__((always_inline));

};



void TFT::writeColorN(RgbColor color, uint16_t n) {
  while (n) {
    write8(color.colorH);
    write8(color.colorL);
    n--;
  }
}




void TFT::write8bitmap(
    RgbColor color,
    RgbColor bgColor,
    uint16_t bitmap,
    uint8_t scale
) {
  uint16_t mask = 0x8000;
  while (mask) {
    if (bitmap & mask) {
      writeColorN(color, scale);
    } else {
      writeColorN(bgColor, scale);
    }
    mask >>= 1;
  }
}





void TFT::write8bitmapWithBorder(
    RgbColor color,
    RgbColor bgColor,
    RgbColor bColor,
    uint16_t prvBitmap,
    uint16_t curBitmap,
    uint16_t nxtBitmap,
    uint8_t scale
) {
  uint16_t borderMask = 0xC000;
  uint16_t mask = 0x8000;
  while (mask) {
    if (curBitmap & mask) {

      if (mask & 0x7FFE
          && ((prvBitmap & borderMask) == borderMask)
          && ((curBitmap & borderMask) == borderMask)
          && ((nxtBitmap & borderMask) == borderMask)) {
        writeColorN(color, scale);
      } else {
        writeColorN(bColor, scale);
      }

    } else {
      writeColorN(bgColor, scale);
    }
    mask >>= 1;
    if (borderMask == 0xC000) {
      borderMask = 0xE000;
    } else {
      borderMask >>= 1;
    }
  }
}





#endif //PBLOCKMAIN_TFT_H
