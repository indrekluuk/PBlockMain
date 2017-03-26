//
// Created by indrek on 25.03.2017.
//

#include "Sheet.h"
#include "Colors.h"
#include "PBlocksDisplay.h"



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
    MCUFRIEND_kbv & tft = Display->tft;
    uint16_t tabX = getTabX();
    tft.fillRect(tabX + 1, 0, TAB_WIDTH - 2, TAB_HEIGHT, selected ? SHEET_BACKGROUND : SHEET_INACTIVE);
    tft.drawFastHLine(tabX + 1 , TAB_HEIGHT , TAB_WIDTH - 2, selected ? SHEET_BACKGROUND : BLACK);
  }
}


void Sheet::drawSheet(bool redrawAll) {
  if (selected && (redrawAll || isDrawnAsSelected != selected)) {
    MCUFRIEND_kbv & tft = Display->tft;
    uint16_t tabX = getTabX();
    if (redrawAll) {
      tft.fillRect(0, TAB_HEIGHT + 1, tft.width(), SHEET_HEIGHT, SHEET_BACKGROUND);
    }
    tft.fillRect(10, TAB_HEIGHT + 10, 50, 7, SHEET_BACKGROUND);
    tft.setCursor(10, TAB_HEIGHT + 10);
    tft.print(tabX);
  }
}


uint16_t Sheet::getTabX() {
  return tabIndex*TAB_WIDTH;
}


