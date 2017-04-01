//
// Created by indrek on 26.03.2017.
//

#include "TFT.h"




void TFT::drawIcon(uint16_t x, uint16_t y, IconBuffer & icon, IconColor iconColor, uint8_t w, uint8_t h, uint8_t scale) {
  setAddrWindow(x, y, x + w - 1, y + h - 1);
  CS_ACTIVE;
  WriteCmd(_MW);

  RgbColor fgColor = iconColor.getForegroundColor();
  RgbColor bgColor = iconColor.getBackgroundColor();

  CD_DATA;

  uint8_t bitmapW = icon.BITMAP_WIDTH*scale;
  uint8_t bitmapH = icon.BITMAP_HEIGHT*scale;
  uint8_t bitmapX = (w - bitmapW) >> 1;
  uint8_t bitmapX2 = bitmapX + bitmapW;
  uint8_t bitmapY = (h - bitmapH) >> 1;
  uint8_t bitmapY2 = bitmapY + bitmapH;


  // background lines before icon
  if (bitmapY > 0) {
    writeColorN(bgColor, bitmapY * w);
  }

  if (iconColor.hasBorder) {
    RgbColor bTopColor = iconColor.hasBorder3d ? RgbColor(COLOR_WHITE) : iconColor.getBorderColor();
    RgbColor bBottomColor = iconColor.hasBorder3d ? RgbColor(COLOR_BLACK) : iconColor.getBorderColor();
    // draw icon with border
    uint16_t prvRow = 0;
    uint16_t curRow = 0;
    uint16_t nxtRow = icon.getRow(0);
    for (uint8_t bRow = 0; bRow < icon.BITMAP_HEIGHT; bRow++) {
      curRow = nxtRow;
      for (uint8_t s = 0; s<scale; s++) {
        if (s == scale-1) {
          nxtRow = (bRow == icon.BITMAP_HEIGHT - 1) ? (uint16_t)0 : icon.getRow(bRow + (uint8_t)1);
        }
        if (bitmapX > 0) {
          writeColorN(bgColor, bitmapX);
        }

        write8bitmapWithBorder(
            fgColor,
            bgColor,
            bTopColor,
            bBottomColor,
            prvRow,
            curRow,
            nxtRow,
            scale);

        if (bitmapX2 < w) {
          writeColorN(bgColor, w - bitmapX2);
        }
        prvRow = curRow;
      }
    }


  } else {
    // draw icon without border
    for (uint8_t bRow = 0; bRow < icon.BITMAP_HEIGHT; bRow++) {
      uint16_t row = icon.getRow(bRow);
      for (uint8_t s = 0; s < scale; s++) {
        if (bitmapX > 0) {
          writeColorN(bgColor, bitmapX);
        }
        write8bitmap(
            fgColor,
            bgColor,
            row,
            scale);
        if (bitmapX2 < w) {
          writeColorN(bgColor, w - bitmapX2);
        }
      }
    }
  }

  // background lines after icon
  if (bitmapY2 < h) {
    writeColorN(bgColor, (h - bitmapY2) * w);
  }

  CS_IDLE;
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
    RgbColor bTopColor,
    RgbColor bBottomColor,
    uint16_t prvBitmap,
    uint16_t curBitmap,
    uint16_t nxtBitmap,
    uint8_t scale
) {
  uint16_t mask = 0x8000;
  uint16_t nextMask;

  uint16_t isPrevious = 0;
  while (mask) {
    nextMask = mask >> 1;
    uint16_t isCurrent = curBitmap & mask;

    if (isCurrent) {
      if ((prvBitmap & mask) != mask) {
        writeColorN(bTopColor, scale);
      } else if ((nxtBitmap & mask) != mask) {
        writeColorN(bBottomColor, scale);
      } else {

        uint16_t isNext = curBitmap & nextMask;
        if (isPrevious && isNext) {
          writeColorN(color, scale);
        } else if (isPrevious) {
          writeColorN(color, scale - (uint16_t)1);
          writeColorN(bBottomColor, 1);
        } else if (isNext) {
          writeColorN(bTopColor, 1);
          writeColorN(color, scale - (uint16_t)1);
        } else {
          writeColorN(bTopColor, 1);
          if (scale > 1) {
            writeColorN(color, scale - (uint16_t)2);
            writeColorN(bBottomColor, 1);
          }
        }

      }
    } else {
      writeColorN(bgColor, scale);
    }

    isPrevious = isCurrent;
    mask = nextMask;
  }
}



void TFT::writeColorN(RgbColor color, uint16_t n) {
  while (n) {
    write8(color.colorH);
    write8(color.colorL);
    n--;
  }
}




