//
// Created by indrek on 25.03.2017.
//

#include "Sheet.h"
#include "PBlocksDisplay.h"



Sheet::Sheet() :
    tabIndex(0xF),
    selected(false),
    isDrawnAsSelected(false)
{
}


void Sheet::init(uint8_t index) {
  tabIndex = index;

  uint8_t i = 0;
  uint16_t w = (uint16_t)(Display->tft.width()-12) / SLOT_COL_COUNT;
  for (uint16_t y=0; y<SLOT_ROW_COUNT; y++) {
    for (uint16_t x=0; x<SLOT_COL_COUNT; x++) {
      programSlots[i++].init(
          w * x + SLOT_SPACING_H,
          (uint16_t)6 + TAB_HEIGHT + SLOT_SPACING_V + y * (ProgramSlot::HEIGHT + SLOT_SPACING_V));
    }
  }
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
    color.setDrawColor(Palette::BLACK);
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
      for (ProgramSlot programSlot : programSlots) {
        programSlot.draw();
      }
    }
  }
}


