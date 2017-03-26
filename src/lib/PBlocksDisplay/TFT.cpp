//
// Created by indrek on 26.03.2017.
//

#include "TFT.h"




void TFT::drawIcon(uint16_t x, uint16_t y, IconBuffer &iconBuffer, uint16_t color, uint16_t bgColor) {
  Serial.println(_MW);
  setAddrWindow(x, y, x + iconBuffer.width - 1, y + iconBuffer.height - 1);
  CS_ACTIVE;
  WriteCmd(_MW);

  uint8_t colorH = color >> 8;
  uint8_t colorL = color & 0xFF;
  uint8_t bgColorH = bgColor >> 8;
  uint8_t bgColorL = bgColor & 0xFF;


  CD_DATA;


  if (iconBuffer.bitmapY > 0) {
    write8n(bgColorH, bgColorL, iconBuffer.bitmapY * iconBuffer.width);
  }

  for (uint16_t bRow = 0; bRow < iconBuffer.BITMAP_HEIGHT; bRow++) {
    for (int16_t s = 0; s<iconBuffer.scale; s++) {
      if (iconBuffer.bitmapX > 0) {
        write8n(bgColorH, bgColorL, iconBuffer.bitmapX);
      }

      if (iconBuffer.hasBorder) {
        uint16_t prvRow = bRow == 0 ? 0 : iconBuffer.bitmap[s==0?bRow-1:bRow];
        uint16_t curRow = iconBuffer.bitmap[bRow];
        uint16_t nxtRow = bRow == iconBuffer.BITMAP_HEIGHT - 1 ? 0 : iconBuffer.bitmap[s==iconBuffer.scale-1 ? bRow+1 : bRow];

        write8bitmapWithBorder(
            colorH,
            colorL,
            bgColorH,
            bgColorL,
            prvRow,
            curRow,
            nxtRow,
            iconBuffer.scale);
      } else {
        write8bitmap(
            colorH,
            colorL,
            bgColorH,
            bgColorL,
            iconBuffer.bitmap[bRow],
            iconBuffer.scale);
      }

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

