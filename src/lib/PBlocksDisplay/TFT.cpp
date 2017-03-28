//
// Created by indrek on 26.03.2017.
//

#include "TFT.h"




void TFT::drawIcon(uint16_t x, uint16_t y, IconBuffer & icon, uint8_t w, uint8_t h, uint8_t scale) {
  setAddrWindow(x, y, x + w - 1, y + h - 1);
  CS_ACTIVE;
  WriteCmd(_MW);

  RgbColor color = icon.color.getDrawColor();
  RgbColor bgColor = icon.color.getBackgroundColor();
  RgbColor bColor = icon.color.getBorderColor();

  CD_DATA;

  uint8_t bitmapW = icon.BITMAP_WIDTH*scale;
  uint8_t bitmapH = icon.BITMAP_HEIGHT*scale;
  uint8_t bitmapX = (w - bitmapW) >> 1;
  uint8_t bitmapX2 = bitmapX + bitmapW;
  uint8_t bitmapY = (h - bitmapH) >> 1;
  uint8_t bitmapY2 = bitmapY + bitmapH;

  if (bitmapY > 0) {
    writeColorN(bgColor, bitmapY * w);
  }

  for (uint8_t bRow = 0; bRow < icon.BITMAP_HEIGHT; bRow++) {
    for (uint8_t s = 0; s<scale; s++) {
      if (bitmapX > 0) {
        writeColorN(bgColor, bitmapX);
      }

      if (icon.color.hasBorder) {
        uint16_t prvRow = bRow == 0 ? 0 : icon.bitmap[s==0?bRow-1:bRow];
        uint16_t curRow = icon.bitmap[bRow];
        uint16_t nxtRow = bRow == bitmapH - 1 ? 0 : icon.bitmap[s==scale-1 ? bRow+1 : bRow];

        write8bitmapWithBorder(
            color,
            bgColor,
            bColor,
            prvRow,
            curRow,
            nxtRow,
            scale);
      } else {
        write8bitmap(
            color,
            bgColor,
            icon.bitmap[bRow],
            scale);
      }

      if (bitmapX2 < w) {
        writeColorN(bgColor, w - bitmapX2);
      }
    }
  }

  if (bitmapY2 < h) {
    writeColorN(bgColor, (h - bitmapY2) * w);
  }

  CS_IDLE;
}

