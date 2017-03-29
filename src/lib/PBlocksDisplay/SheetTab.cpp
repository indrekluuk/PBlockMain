//
// Created by indrek on 29.03.2017.
//

#include "SheetTab.h"
#include "PBlocksDisplay.h"




void SheetTab::draw(uint16_t x, uint16_t w, uint16_t h, bool active) {
  Display->tft.drawFastHLine(x + 1 , h , w - 2, active ? COLOR_SHEET_BACKGROUND : COLOR_BLACK);

  if (tabIcon) {
    drawIcon(x + 1, w - 2, h, active);
  } else if (tabLabel) {
    drawLabel(x + 1, w - 2, h, active);
  } else {
    Display->tft.fillRect(x + 1, 0, w - 2, h, active ? COLOR_SHEET_BACKGROUND : COLOR_SHEET_INACTIVE);
  }
}



void SheetTab::drawIcon(uint16_t x, uint16_t w, uint16_t h, bool active) {
  if (active) {
    Display->tft.drawIcon(x, 0, *tabIcon, w, h, 2);
  } else {
    IconColor tmp = tabIcon->color;
    tabIcon->color.setDrawColor(Palette::BLACK);
    tabIcon->color.setBackgroundColor(Palette::SHEET_INACTIVE);
    tabIcon->color.setNoBorder();
    Display->tft.drawIcon(x, 0, *tabIcon, w, h, 2);
    tabIcon->color = tmp;
  }
}



void SheetTab::drawLabel(uint16_t x, uint16_t w, uint16_t h, bool active) {
  TFT & tft = Display->tft;
  tft.fillRect(x, 0, w, h, active ? COLOR_SHEET_BACKGROUND : COLOR_SHEET_INACTIVE);
  if (tabLabel) {
    tft.setCursor(x + 10, h / 2 - 6);
    tft.setTextColor(active ? COLOR_WHITE : COLOR_BLACK);
    tft.setTextSize(2);
    tft.print(tabLabel);
  }
}






