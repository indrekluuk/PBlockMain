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


  // background lines before icon
  if (bitmapY > 0) {
    writeColorN(bgColor, bitmapY * w);
  }

  if (icon.color.hasBorder) {
    // draw icon with border
    uint16_t prvRow = 0;
    uint16_t curRow = 0;
    uint16_t nxtRow = 0;
    for (uint8_t bRow = 0; bRow < icon.BITMAP_HEIGHT; bRow++) {
      curRow = icon.bitmap[bRow];
      nxtRow = curRow;
      for (uint8_t s = 0; s<scale; s++) {
        if (s == scale-1) {
          nxtRow = (bRow == icon.BITMAP_HEIGHT - 1) ? (uint16_t)0 : icon.bitmap[bRow + 1];
        }
        if (bitmapX > 0) {
          writeColorN(bgColor, bitmapX);
        }

        if (icon.color.hasBorder) {
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
        prvRow = curRow;
      }
    }


  } else {
    // draw icon without border
    for (uint8_t bRow = 0; bRow < icon.BITMAP_HEIGHT; bRow++) {
      for (uint8_t s = 0; s < scale; s++) {
        if (bitmapX > 0) {
          writeColorN(bgColor, bitmapX);
        }
        write8bitmap(
            color,
            bgColor,
            icon.bitmap[bRow],
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
    RgbColor bColor,
    uint16_t prvBitmap,
    uint16_t curBitmap,
    uint16_t nxtBitmap,
    uint8_t scale
) {
  uint16_t mask = 0x8000;
  uint16_t borderMask = 0xC000;

  while (mask) {
    if (curBitmap & mask) {
      if ((prvBitmap & mask) != mask || (nxtBitmap & mask) != mask) {
        if ((prvBitmap & mask) != mask ) {
          writeColorN(RgbColor(COLOR_WHITE), scale); // todo use border color
        } else {
          writeColorN(RgbColor(COLOR_BLACK), scale); // todo use border color
        }
      } else {
        uint16_t borderCheck = curBitmap & borderMask;
        if (borderCheck == borderMask && (mask & 0x7FFE)) {
          writeColorN(color, scale);
        } else {
          if ((borderCheck & ~mask) > mask) {
            writeColorN(color, scale - (uint16_t)1);
            writeColorN(RgbColor(COLOR_BLACK), 1); // todo use border color
          } else if (borderCheck > mask) {
            writeColorN(RgbColor(COLOR_WHITE), 1); // todo use border color
            writeColorN(color, scale - (uint16_t)1);
          } else {
            writeColorN(RgbColor(COLOR_WHITE), 1); // todo use border color
            if (scale > 1) {
              writeColorN(color, scale - (uint16_t)2);
              writeColorN(RgbColor(COLOR_BLACK), 1); // todo use border color
            }
          }
        }
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



void TFT::writeColorN(RgbColor color, uint16_t n) {
  while (n) {
    write8(color.colorH);
    write8(color.colorL);
    n--;
  }
}




