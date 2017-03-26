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
    void drawIcon(uint16_t x, uint16_t y, IconBuffer & iconBuffer);


private:
    inline void write8n(uint8_t h, uint8_t l, uint16_t n) __attribute__((always_inline));
    inline void write8bitmap(
        uint8_t colorH,
        uint8_t colorL,
        uint8_t bgColorH,
        uint8_t bgColorL,
        uint16_t bitmap,
        uint8_t scale) __attribute__((always_inline));

};



void TFT::write8n(uint8_t h, uint8_t l, uint16_t n) {
  while (n) {
    write8(h);
    write8(l);
    n--;
  }
}




void TFT::write8bitmap(
    uint8_t colorH,
    uint8_t colorL,
    uint8_t bgColorH,
    uint8_t bgColorL,
    uint16_t bitmap,
    uint8_t scale
) {
  uint16_t mask = 0x8000;
  while (mask) {
    if (bitmap & mask) {
      write8n(colorH, colorL, scale);
    } else {
      write8n(bgColorH, bgColorL, scale);
    }
    mask >>= 1;
  }
}





#endif //PBLOCKMAIN_TFT_H
