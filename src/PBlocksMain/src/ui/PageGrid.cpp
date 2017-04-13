//
// Created by indrek on 11.04.2017.
//

#include "PageGrid.h"
#include "PBlocksUserInterface.h"



void PageGrid::clearPage() {
  TFT & tft = UI->tft;
  tft.fillRect(0, TOP, SCREEN_WIDTH, HEIGHT, COLOR_GRAY50);
}



void PageGrid::drawEmptySlot(uint8_t col, uint8_t row, uint16_t cursorColor) {
  TFT & tft = UI->tft;
  uint16_t x = getSlotX(col);
  uint16_t y = getSlotY(row);

  tft.drawRect(x, y, SLOT_WIDTH, SLOT_HEIGHT, COLOR_GRAY33);
  tft.fillRect(x + 1, y + 1, SLOT_WIDTH - 2, SLOT_HEIGHT - 2, COLOR_GRAY50);
  drawCursor(x, y, cursorColor);
}



void PageGrid::drawCursor(uint16_t slotX, uint16_t slotY, uint16_t color) {
  UI->tft.fillRect(
      slotX - 7,
      slotY + 1,
      4,
      SLOT_HEIGHT - 2,
      color);
}


uint16_t PageGrid::getCursorColor(bool isActive) {
  if (isActive) {
    return (uint16_t)(((millis() & 0x200) != 0) ? COLOR_WHITE : COLOR_GRAY33);
  } else {
    return COLOR_GRAY33;
  }
}





uint16_t PageGrid::getSlotX(uint8_t col) {
  return SLOT_AREA_WIDTH * col + SLOT_SPACING*(uint16_t)2;
}

uint16_t PageGrid::getSlotY(uint8_t row) {
  return TOP + SLOT_SPACING*(uint16_t)2 + row * (SLOT_HEIGHT + SLOT_SPACING);
}

uint8_t PageGrid::getSlotIndex(uint8_t col, uint8_t row) {
  return row * SLOT_COL_COUNT + col;
}

uint8_t PageGrid::getSlotCol(uint8_t index) {
  return index % SLOT_COL_COUNT;
}

uint8_t PageGrid::getSlotRow(uint8_t index) {
  return index / SLOT_COL_COUNT;
}

uint8_t PageGrid::getTapCol(uint16_t x) {
  for (uint8_t col=0; col<PageGrid::SLOT_COL_COUNT - 1; col++) {
    uint16_t slotX = PageGrid::getSlotX(col);
    if (x < slotX + PageGrid::SLOT_WIDTH) {
      return col;
    }
  }
  return PageGrid::SLOT_COL_COUNT - 1;
}

uint8_t PageGrid::getTapRow(uint16_t y) {
  for (uint8_t row=0; row < PageGrid::SLOT_ROW_COUNT - 1; row++) {
    uint16_t slotY = PageGrid::getSlotY(row);
    if (y < slotY + PageGrid::SLOT_HEIGHT) {
      return row;
    }
  }
  return PageGrid::SLOT_ROW_COUNT - 1;
}

