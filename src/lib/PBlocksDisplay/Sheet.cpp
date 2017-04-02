//
// Created by indrek on 25.03.2017.
//

#include "Sheet.h"
#include "PBlocksDisplay.h"
#include <PBlocksProgram.h>
#include "Arduino.h"



uint16_t Sheet::slotAreaWidth = 0;


Sheet::Sheet() :
    tabIndex(0xF),
    selected(false),
    isDrawnAsSelected(false)
{
}


void Sheet::init(uint8_t index) {
  tabIndex = index;
  slotAreaWidth = (uint16_t)(Display->tft.width()-SLOT_SPACING*(uint16_t)2) / SLOT_COL_COUNT;
}

void Sheet::tap(uint16_t x, uint16_t y) {
  uint16_t tabX = getTabX();
  if (isTapIn(x, tabX, TAB_WIDTH) && isTapIn(y, 0, TAB_HEIGHT)) {
    Display->setActiveTab(tabIndex);
  }
}



void Sheet::setSelected(bool isSelected) {
  selected = isSelected;
}

bool Sheet::isSelected() {
  return selected;
}



void Sheet::draw(bool redrawAll) {
  uint32_t m = millis();
  drawTab(redrawAll);
  drawSheet(redrawAll);

  if (selected && isDrawnAsSelected != selected) {
    Display->tft.setTextSize(1);
    Display->tft.setTextColor(COLOR_WHITE, COLOR_BLACK);
    Display->tft.setCursor(10, 310);
    Display->tft.print(millis()-m);
    Display->tft.print("  ");
  }

  isDrawnAsSelected = selected;
}


void Sheet::updateCursor(bool isActive) {
  drawCursorSpaces(getSlotX(0), getSlotY(0), isActive);
}


void Sheet::drawTab(bool redrawAll) {
  if (redrawAll || isDrawnAsSelected != selected) {
    uint16_t x = getTabX() + (uint16_t)1;
    uint8_t w = TAB_WIDTH - 2;

    Display->tft.drawFastHLine(x , TAB_HEIGHT , w, selected ? COLOR_GRAY50 : COLOR_BLACK);
    if (tabIcon) {
      drawTabIcon(x, w, TAB_HEIGHT);
    } else if (tabLabel) {
      drawTabLabel(x, w, TAB_HEIGHT);
    } else {
      Display->tft.fillRect(x, 0, w, TAB_HEIGHT, selected ? COLOR_GRAY50 : COLOR_GRAY33);
    }
  }
}

void Sheet::drawTabIcon(uint16_t x, uint8_t w, uint8_t h) {
  if (selected) {
    Display->tft.drawIcon(x, 0, *tabIcon, tabIcon->getColor(), w, h, 2);
  } else {
    IconColor color = tabIcon->getColor();
    color.setForegroundColor(Palette::BLACK);
    color.setBackgroundColor(Palette::GRAY33);
    color.setNoBorder();
    Display->tft.drawIcon(x, 0, *tabIcon, color, w, h, 2);
  }
}

void Sheet::drawTabLabel(uint16_t x, uint8_t w, uint8_t h) {
  TFT & tft = Display->tft;
  if (selected) {
    tft.setTextColor(COLOR_WHITE, COLOR_GRAY50);
  } else {
    tft.setTextColor(COLOR_BLACK, COLOR_GRAY33);
  }
  tft.setTextSize(2);
  tft.startTextFillBox(x, 0, w, h, 10, (h >> 1) - (uint8_t)6);
  if (tabLabel) {
    tft.print(tabLabel);
  }
  tft.finishTextFillBox();
}



void Sheet::drawSheet(bool redrawAll) {
  if (selected) {
    TFT & tft = Display->tft;

    if (redrawAll) {
      tft.fillRect(0, TAB_HEIGHT + 1, tft.width(), SHEET_HEIGHT, COLOR_GRAY50);
    }

    if (redrawAll || isDrawnAsSelected != selected) {
      uint8_t i = 0;
      for (uint8_t row=0; row<SLOT_ROW_COUNT; row++) {
        for (uint8_t col=0; col<SLOT_COL_COUNT; col++) {
          uint16_t slotX = getSlotX(col);
          uint16_t slotY = getSlotY(row);
          drawCursorSpaces(slotX, slotY, false);
          drawProgramSlot(slotX, slotY, i++);
        }
      }
    }
  }
}


void Sheet::drawCursorSpaces(uint16_t slotX, uint16_t slotY, bool active) {
  TFT & tft = Display->tft;
  bool isVisible = tabIndex < Program->FUNCTION_COUNT;

  uint16_t color;
  if (isVisible) {
    color = active ? COLOR_WHITE : COLOR_GRAY33;
  } else {
    color = COLOR_GRAY50;
  }

  tft.fillRect(
      slotX - 7,
      slotY,
      4,
      SLOT_HEIGHT,
      color);
}


void Sheet::drawEmptySlot(uint16_t x, uint16_t y) {
  TFT & tft = Display->tft;
  tft.drawRect(x, y, SLOT_WIDTH, SLOT_HEIGHT, COLOR_BLACK);
  tft.fillRect(x + 1, y + 1, SLOT_WIDTH - 2, SLOT_HEIGHT - 2, COLOR_GRAY50);
}


void Sheet::drawProgramSlot(uint16_t x, uint16_t y, uint8_t index) {
  TFT & tft = Display->tft;

  ProgramNode * node = nullptr;

  if (tabIndex < Program->FUNCTION_COUNT) {
    ProgramFunction & function = Program->functions[tabIndex];
    if (index < function.NODE_COUNT) {
      node = &function.nodes[index];
    }
  }

  if (node == nullptr || node->isEmpty()) {
    drawEmptySlot(x, y);
  } else {
    uint16_t bgColor = index == 0 ? COLOR_GRAY85 : COLOR_GRAY66;

    tft.setTextSize(1);
    tft.setTextColor(COLOR_BLACK, bgColor);

    //tft.drawRect(x, y, SLOT_WIDTH, SLOT_HEIGHT, COLOR_WHITE);
    tft.drawFastHLine(x, y, SLOT_WIDTH, index == 0 ? COLOR_WHITE : COLOR_GRAY85);
    tft.drawFastHLine(x, y + SLOT_HEIGHT - 1, SLOT_WIDTH, index == 0 ? COLOR_GRAY33 : COLOR_BLACK);
    tft.drawFastVLine(x, y, SLOT_HEIGHT, index == 0 ? COLOR_WHITE : COLOR_GRAY85);
    tft.drawFastVLine(x + SLOT_WIDTH - 1, y, SLOT_HEIGHT, index == 0 ? COLOR_GRAY33 : COLOR_BLACK);

    IconBuffer & icon = node->getModule()->icon;
    IconColor color = icon.getColor();
    color.setBackgroundColor(Palette::GRAY66);
    if (index == 0) color.setBackgroundColor(Palette::GRAY85);
    color.setNoBorder();
    tft.drawIcon(x + 1, y + 1, icon, color, 38, 38, 2);

    tft.startTextFillBox(x + 39, y + 1, SLOT_WIDTH - 40, 38, 5, 15);
    tft.print("M01");
    tft.finishTextFillBox();

    tft.startTextFillBox(x + 1, y + 39, SLOT_WIDTH - 2, SLOT_HEIGHT - 40, 5, 5);
    tft.print("1 sek aaaa");
    tft.finishTextFillBox();


  }
}





uint16_t Sheet::getTabX() {
  return tabIndex*TAB_WIDTH;
}

uint16_t Sheet::getSlotX(uint8_t col) {
  return slotAreaWidth * col + SLOT_SPACING*(uint16_t)2;
}

uint16_t Sheet::getSlotY(uint8_t row) {
  return TAB_HEIGHT + SLOT_SPACING*(uint16_t)2 + row * (SLOT_HEIGHT + SLOT_SPACING);
}



