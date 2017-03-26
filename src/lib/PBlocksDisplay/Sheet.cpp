//
// Created by indrek on 25.03.2017.
//

#include "Sheet.h"
#include "Colors.h"
#include "PBlocksDisplay.h"




Sheet::Sheet() : tft(PBlocksDisplay::tft) {
}



void Sheet::init(PBlocksDisplay * display, int8_t tabIndex, int16_t tabX, int16_t tabW) {
  this->display = display;
  this->tabIndex = tabIndex;
  this->tabX = tabX;
  this->tabW = tabW;
  tabTouchRegion.init(tabX, 0, tabW, TAB_HEIGHT, this, &Sheet::tabClicked);
}


void Sheet::tabClicked() {
  display->setActiveTab(tabIndex);
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
    tft.fillRect(tabX + 1, 0, tabW - 2, TAB_HEIGHT, selected ? SHEET_BACKGROUND : SHEET_INACTIVE);
    tft.drawFastHLine(tabX + 1 , TAB_HEIGHT , tabW - 2, selected ? SHEET_BACKGROUND : BLACK);
  }
}


void Sheet::drawSheet(bool redrawAll) {
  if (selected && (redrawAll || isDrawnAsSelected != selected)) {
    if (redrawAll) {
      tft.fillRect(0, TAB_HEIGHT + 1, tft.width(), SHEET_HEIGHT, SHEET_BACKGROUND);
    }
    tft.fillRect(10, TAB_HEIGHT + 10, 50, 7, SHEET_BACKGROUND);
    tft.setCursor(10, TAB_HEIGHT + 10);
    tft.print(tabX);
  }
}



