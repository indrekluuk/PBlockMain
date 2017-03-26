//
// Created by indrek on 26.03.2017.
//

#include "TFT.h"




void TFT::drawIcon(uint16_t x, uint16_t y, IconBuffer &iconBuffer) {
  Serial.println(_MW);
  setAddrWindow(x, y, x + iconBuffer.width - 1, y + iconBuffer.height - 1);
  CS_ACTIVE;
  WriteCmd(_MW);

  uint8_t colorH = iconBuffer.color >> 8;
  uint8_t colorL = iconBuffer.color & 0xFF;
  uint8_t bgColorH = iconBuffer.bgColor >> 8;
  uint8_t bgColorL = iconBuffer.bgColor & 0xFF;


  CD_DATA;


  if (iconBuffer.bitmapY > 0) {
    write8n(bgColorH, bgColorL, iconBuffer.bitmapY * iconBuffer.width);
  }

  for (uint16_t bRow = 0; bRow < iconBuffer.BITMAP_HEIGHT; bRow++) {
    for (uint16_t s = 0; s<iconBuffer.scale; s++) {
      if (iconBuffer.bitmapX > 0) {
        write8n(bgColorH, bgColorL, iconBuffer.bitmapX);
      }

      write8bitmap(
          colorH,
          colorL,
          bgColorH,
          bgColorL,
          iconBuffer.bitmap[bRow],
          iconBuffer.scale);

      if (iconBuffer.getBitmapX2() < iconBuffer.width) {
        write8n(bgColorH, bgColorL, iconBuffer.width - iconBuffer.getBitmapX2());
      }
    }
  }

  if (iconBuffer.getBitmapY2() < iconBuffer.height) {
    write8n(bgColorH, bgColorL, (iconBuffer.height - iconBuffer.getBitmapY2())*iconBuffer.width);
  }

  CS_IDLE;
}

