//
// Created by indrek on 25.03.2017.
//

#include "Sheet.h"
#include "Colors.h"
#include <MCUFRIEND_kbv.h>



extern MCUFRIEND_kbv tft;



void Sheet::init(int16_t tabX, int16_t tabW) {
  this->tabX = tabX;
  this->tabW = tabW;
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
  if (selected) {
    if (redrawAll) {
      tft.fillRect(0, TAB_HEIGHT + 1, tft.width(), SHEET_HEIGHT, SHEET_BACKGROUND);
    }
    tft.fillRect(10, TAB_HEIGHT + 10, 50, 7, SHEET_BACKGROUND);
    tft.setCursor(10, TAB_HEIGHT + 10);
    tft.print(tabX);
  }
}



