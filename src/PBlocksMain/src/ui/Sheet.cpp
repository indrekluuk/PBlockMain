//
// Created by indrek on 25.03.2017.
//

#include "Sheet.h"
#include "PBlocksUserInterface.h"
#include "../program/PBlocksProgram.h"



uint16_t Sheet::slotAreaWidth = 0;


Sheet::Sheet() {
}


void Sheet::init(uint8_t index) {
  tab.index = index;
  slotAreaWidth = (uint16_t)(UI->tft.width()-SLOT_SPACING*(uint16_t)2) / SLOT_COL_COUNT;
}

void Sheet::tap(uint16_t x, uint16_t y) {

  if (y < tab.HEIGHT) {
    uint16_t tabX = tab.getTabX();
    if (isTapIn(x, tabX, tab.WIDTH) && isTapIn(y, 0, tab.HEIGHT)) {
      UI->setActiveTab(tab.index);
    }

  } else if (tab.isSelected) {
    for (uint8_t row=0; row<SLOT_ROW_COUNT; row++) {
      uint16_t slotY = getSlotY(row);
      if (isTapBetween(y, slotY, slotY + SLOT_HEIGHT)) {
        for (uint8_t col=0; col<SLOT_COL_COUNT; col++) {
          uint16_t slotX = getSlotX(col);
          if (isTapBetween(x, slotX, slotX + SLOT_WIDTH)) {
            setActiveNode(slotX, slotY, getSlotIndex(row, col));
          }
        }
      }
    }
  }
}


void Sheet::setActiveNode(uint16_t x, uint16_t y, uint8_t selectedNodeIndex) {
  ProgramFunction * function = Program->getFunction(tab.index);

  if (function) {
    uint8_t currentNodeIndex = function->getActiveNodeIndex();
    selectedNodeIndex = function->setActiveNode(selectedNodeIndex);

    if (currentNodeIndex != selectedNodeIndex) {

      if (function->getNode(currentNodeIndex)) {
        uint16_t currentSlotX = getSlotXByIndex(currentNodeIndex);
        uint16_t currentSlotY = getSlotYByIndex(currentNodeIndex);
        drawProgramSlot(
            currentSlotX,
            currentSlotY,
            currentNodeIndex);
        drawCursor(currentSlotX, currentSlotY, currentNodeIndex);
      }

      function->setActiveNode(selectedNodeIndex);
      drawProgramSlot(
          x,
          y,
          selectedNodeIndex);
    }
  }
}



void Sheet::setSelected(bool isSelected) {
  tab.isSelected = isSelected;
}

bool Sheet::isSelected() {
  return tab.isSelected;
}



void Sheet::updateCursor() {
  ProgramFunction * function = Program->getFunction(tab.index);
  if (function) {
    if (function->getActiveNode()) {
      uint8_t index = function->getActiveNodeIndex();
      drawCursor(
          getSlotXByIndex(index),
          getSlotYByIndex(index),
          index);
    }
  }
}




void Sheet::draw(bool redrawAll) {
  uint32_t m = millis();

  tab.draw(redrawAll);
  drawSheet(redrawAll);

  // render time
  if (tab.isSelected && tab.needsRedraw()) {
    UI->tft.setTextSize(1);
    UI->tft.setTextColor(COLOR_WHITE, COLOR_BLACK);
    UI->tft.setCursor(10, 310);
    UI->tft.print((uint16_t)(millis() - m));
    UI->tft.print("  ");
  }

  tab.drawingDone();
}





void Sheet::drawSheet(bool redrawAll) {
  if (tab.isSelected) {
    TFT & tft = UI->tft;

    if (redrawAll) {
      tft.fillRect(0, tab.HEIGHT + 1, tft.width(), SHEET_HEIGHT, COLOR_GRAY50);
    }

    if (redrawAll || tab.needsRedraw()) {
      uint8_t i = 0;
      for (uint8_t row=0; row<SLOT_ROW_COUNT; row++) {
        for (uint8_t col=0; col<SLOT_COL_COUNT; col++) {
          uint16_t slotX = getSlotX(col);
          uint16_t slotY = getSlotY(row);
          drawCursor(slotX, slotY, i);
          drawProgramSlot(slotX, slotY, i);
          i++;
        }
      }
    }
  }
}


void Sheet::drawCursor(uint16_t slotX, uint16_t slotY, uint8_t index) {
  TFT & tft = UI->tft;
  ProgramFunction * function = Program->getFunction(tab.index);

  uint16_t color;
  if (function) {
    color = (uint16_t)(index == function->getActiveNodeIndex() && ((millis() & 0x200) != 0) ? COLOR_WHITE : COLOR_GRAY33);
  } else {
    color = COLOR_GRAY50;
  }

  tft.fillRect(
      slotX - 7,
      slotY + 1,
      4,
      SLOT_HEIGHT - 2,
      color);
}


void Sheet::drawEmptySlot(uint16_t x, uint16_t y) {
  TFT & tft = UI->tft;
  tft.drawRect(x, y, SLOT_WIDTH, SLOT_HEIGHT, COLOR_GRAY33);
  tft.fillRect(x + 1, y + 1, SLOT_WIDTH - 2, SLOT_HEIGHT - 2, COLOR_GRAY50);
}


void Sheet::drawProgramSlot(uint16_t x, uint16_t y, uint8_t index) {
  TFT & tft = UI->tft;

  ProgramFunction * function = Program->getFunction(tab.index);
  ProgramNode * node = nullptr;
  if (function) {
    node = function->getNode(index);
  }

  if (node == nullptr || node->isEmpty()) {
    drawEmptySlot(x, y);
  } else {
    uint16_t bgColor;
    uint16_t bTopColor;
    uint16_t bBottomColor;

    Icon & icon = node->getModule()->icon;
    IconColor color = icon.getColor();
    color.setNoBorder();

    if (function->getActiveNodeIndex() == index) {
      bgColor = COLOR_GRAY85;
      bTopColor = COLOR_WHITE;
      bBottomColor = COLOR_GRAY33;
      color.setBackgroundColor(Palette::GRAY85);
    } else {
      bgColor = COLOR_GRAY66;
      bTopColor = COLOR_GRAY85;
      bBottomColor = COLOR_BLACK;
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


  }
}





uint8_t Sheet::getSlotIndex(uint8_t row, uint8_t col) {
  return row * SLOT_COL_COUNT + col;
}

uint16_t Sheet::getSlotXByIndex(uint8_t index) {
  return getSlotX(index % SLOT_COL_COUNT);
}

uint16_t Sheet::getSlotYByIndex(uint8_t index) {
  return getSlotY(index / SLOT_COL_COUNT);
}

uint16_t Sheet::getSlotX(uint8_t col) {
  return slotAreaWidth * col + SLOT_SPACING*(uint16_t)2;
}

uint16_t Sheet::getSlotY(uint8_t row) {
  return tab.HEIGHT + SLOT_SPACING*(uint16_t)2 + row * (SLOT_HEIGHT + SLOT_SPACING);
}



