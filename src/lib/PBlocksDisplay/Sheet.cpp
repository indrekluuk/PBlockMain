//
// Created by indrek on 25.03.2017.
//

#include "Sheet.h"
#include "PBlocksDisplay.h"
#include <PBlocksProgram.h>



Sheet::Sheet() :
    tabIndex(0xF),
    selected(false),
    isDrawnAsSelected(false)
{
}


void Sheet::init(uint8_t index) {
  tabIndex = index;
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
  drawTab(redrawAll);
  drawSheet(redrawAll);
  isDrawnAsSelected = selected;
}



void Sheet::drawTab(bool redrawAll) {
  if (redrawAll || isDrawnAsSelected != selected) {
    uint16_t x = getTabX() + (uint16_t)1;
    uint8_t w = TAB_WIDTH - 2;

    Display->tft.drawFastHLine(x , TAB_HEIGHT , w, selected ? COLOR_SHEET_BACKGROUND : COLOR_BLACK);
    if (tabIcon) {
      drawTabIcon(x, w, TAB_HEIGHT);
    } else if (tabLabel) {
      drawTabLabel(x, w, TAB_HEIGHT);
    } else {
      Display->tft.fillRect(x, 0, w, TAB_HEIGHT, selected ? COLOR_SHEET_BACKGROUND : COLOR_SHEET_INACTIVE);
    }
  }
}

void Sheet::drawTabIcon(uint16_t x, uint8_t w, uint8_t h) {
  if (selected) {
    Display->tft.drawIcon(x, 0, *tabIcon, tabIcon->getColor(), w, h, 2);
  } else {
    IconColor color = tabIcon->getColor();
    color.setForegroundColor(Palette::BLACK);
    color.setBackgroundColor(Palette::SHEET_INACTIVE);
    color.setNoBorder();
    Display->tft.drawIcon(x, 0, *tabIcon, color, w, h, 2);
  }
}

void Sheet::drawTabLabel(uint16_t x, uint8_t w, uint8_t h) {
  TFT & tft = Display->tft;
  tft.fillRect(x, 0, w, h, selected ? COLOR_SHEET_BACKGROUND : COLOR_SHEET_INACTIVE);
  if (tabLabel) {
    tft.setCursor(x + 10, h / 2 - 6);
    tft.setTextColor(selected ? COLOR_WHITE : COLOR_BLACK);
    tft.setTextSize(2);
    tft.print(tabLabel);
  }
}

uint16_t Sheet::getTabX() {
  return tabIndex*TAB_WIDTH;
}





void Sheet::drawSheet(bool redrawAll) {
  if (selected) {
    TFT & tft = Display->tft;

    if (redrawAll) {
      tft.fillRect(0, TAB_HEIGHT + 1, tft.width(), SHEET_HEIGHT, COLOR_SHEET_BACKGROUND);
    }

    if (redrawAll || isDrawnAsSelected != selected) {
      uint8_t i = 0;
      uint16_t w = (uint16_t)(Display->tft.width()-12) / SLOT_COL_COUNT;
      for (uint16_t y=0; y<SLOT_ROW_COUNT; y++) {
        for (uint16_t x=0; x<SLOT_COL_COUNT; x++) {
          drawProgramSlot(
              i++,
              w * x + SLOT_SPACING_H,
              (uint16_t)6 + TAB_HEIGHT + SLOT_SPACING_V + y * (SLOT_HEIGHT + SLOT_SPACING_V)
          );
        }
      }
    }
  }
}



void Sheet::drawProgramSlot(uint8_t index, uint16_t x, uint16_t y) {
  TFT & tft = Display->tft;

  ProgramNode * node = nullptr;

  if (tabIndex < Program->FUNCTION_COUNT) {
    ProgramFunction & function = Program->functions[tabIndex];
    if (index < function.NODE_COUNT) {
      node = &function.nodes[index];
    }
  }

  if (node == nullptr || node->isEmpty()) {
    tft.drawRect(x, y, SLOT_WIDTH, SLOT_HEIGHT, COLOR_BLACK);
    tft.fillRect(x + 1, y + 1, SLOT_WIDTH - 2, SLOT_HEIGHT - 2, COLOR_SHEET_BACKGROUND);
  } else {
    IconBuffer & icon = node->getModule()->icon;

    tft.fillRect(x + 1, y + 1, SLOT_WIDTH - 2, SLOT_HEIGHT - 2, COLOR_GRAY);

    tft.setTextSize(1);
    tft.setTextColor(COLOR_BLACK);
    tft.drawRect(x, y, SLOT_WIDTH, SLOT_HEIGHT, COLOR_WHITE);

    IconColor color = icon.getColor();
    color.setBackgroundColor(Palette::TEST);
    color.setNoBorder();
    tft.drawIcon(x + 6, y + 4, icon, color, 32, 32, 2);

    tft.setCursor(x + 44, y + 18);
    tft.print("M01");
    tft.setCursor(x + 6, y + 46);
    tft.print("1 sek");
  }
}



