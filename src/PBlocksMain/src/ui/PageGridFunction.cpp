//
// Created by indrek on 25.03.2017.
//

#include "PageGridFunction.h"
#include "PBlocksUserInterface.h"




void PageGridFunction::tap(uint16_t x, uint16_t y) {
  setActiveNode(
      getTapCol(x),
      getTapRow(y));
}


void PageGridFunction::setActiveNode(uint8_t col, uint8_t row) {
  uint8_t currentNodeIndex = function.getActiveNodeIndex();
  uint8_t selectedNodeIndex = function.setActiveNode(getSlotIndex(col, row));

  if (currentNodeIndex != selectedNodeIndex) {
    function.setActiveNode(selectedNodeIndex);
    drawSlot(
        getSlotCol(currentNodeIndex),
        getSlotRow(currentNodeIndex));
    drawSlot(
        col,
        row);
  }
}



void PageGridFunction::draw(bool redrawAll) {
  if (redrawAll) {
    clearPage();
  }

  for (uint8_t row=0; row<SLOT_ROW_COUNT; row++) {
    for (uint8_t col=0; col<SLOT_COL_COUNT; col++) {
      drawSlot(col, row);
    }
  }
}


void PageGridFunction::drawSlot(uint8_t col, uint8_t row) {
    uint8_t nodeIndex = getSlotIndex(col, row);
    bool isNodeSelected = function.getActiveNodeIndex() == nodeIndex;

    ProgramNode * node = function.getNode(nodeIndex);

    if (node != nullptr && !node->isEmpty()) {
      drawProgramSlot(col, row, node, isNodeSelected);
    } else {
      drawEmptySlot(col, row, getCursorColor(isNodeSelected));
    }
}







void PageGridFunction::drawProgramSlot(uint8_t col, uint8_t row, ProgramNode * node, bool isActive) {
  TFT & tft = UI->tft;
  uint16_t x = getSlotX(col);
  uint16_t y = getSlotY(row);

  uint16_t bgColor;
  uint16_t bTopColor;
  uint16_t bBottomColor;

  Icon & icon = node->getModule()->icon;
  IconColor color = icon.getColor();
  color.setNoBorder();

  if (isActive) {
    bgColor = COLOR_GRAY85;
    bTopColor = COLOR_WHITE;
    bBottomColor = COLOR_WHITE;
    color.setBackgroundColor(Palette::GRAY85);
  } else {
    bgColor = COLOR_GRAY66;
    bTopColor = COLOR_GRAY33;
    bBottomColor = COLOR_GRAY33;
    color.setBackgroundColor(Palette::GRAY66);
  }

  tft.setTextSize(1);
  tft.setTextColor(COLOR_BLACK, bgColor);

  //tft.drawRect(x, y, SLOT_WIDTH, SLOT_HEIGHT, COLOR_WHITE);
  tft.drawFastHLine(x, y, SLOT_WIDTH, bTopColor);
  tft.drawFastVLine(x, y, SLOT_HEIGHT, bTopColor);
  tft.drawFastHLine(x, y + SLOT_HEIGHT - 1, SLOT_WIDTH, bBottomColor);
  tft.drawFastVLine(x + SLOT_WIDTH - 1, y, SLOT_HEIGHT, bBottomColor);

  tft.drawIcon(x + (uint16_t)1, y + (uint16_t)1, icon, color, 38, 38, 2);

  tft.startTextFillBox(x + (uint16_t)39, y + (uint16_t)1, SLOT_WIDTH - 40, 38, 5, 15);
  tft.print("M01");
  tft.finishTextFillBox();

  tft.startTextFillBox(x + (uint16_t)1, y + (uint16_t)39, SLOT_WIDTH - 2, SLOT_HEIGHT - 40, 5, 5);
  tft.print("1 sek aaaa");
  tft.finishTextFillBox();

  drawCursor(x, y, getCursorColor(isActive));
}




void PageGridFunction::updateCursor() {
  if (function.getActiveNode()) {
    uint8_t index = function.getActiveNodeIndex();
    drawCursor(
        getSlotX(getSlotCol(index)),
        getSlotY(getSlotRow(index)),
        getCursorColor(true));
  }
}


