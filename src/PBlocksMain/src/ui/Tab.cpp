//
// Created by indrek on 7.04.2017.
//

#include "Tab.h"
#include "PBlocksUserInterface.h"



Tab::Tab() :
    index(0xF),
    isSelected(false),
    isDrawnAsSelected(false)
{
}



uint16_t Tab::getTabX() {
  return index*WIDTH;
}




void Tab::draw(bool redrawAll) {
  if (redrawAll || needsRedraw()) {
    uint16_t x = getTabX() + (uint16_t)1;
    uint8_t w = WIDTH - 2;

    UI->tft.drawFastHLine(x , HEIGHT , w, isSelected ? COLOR_GRAY50 : COLOR_BLACK);
    if (icon) {
      drawIcon(x, w, HEIGHT);
    } else if (label) {
      drawLabel(x, w, HEIGHT);
    } else {
      UI->tft.fillRect(x, 0, w, HEIGHT, isSelected ? COLOR_GRAY50 : COLOR_GRAY33);
    }
  }
}



void Tab::drawIcon(uint16_t x, uint8_t w, uint8_t h) {
  if (isSelected) {
    IconColor color = icon->getColor();

    color.setForegroundColor(Palette::WHITE);
    color.setBackgroundColor(Palette::GRAY50);
    color.setNoBorder();


    /*
    color.setForegroundColor(Palette::GRAY50);
    color.setBackgroundColor(Palette::GRAY50);
    color.setBorderColor(Palette::WHITE);
     */

    UI->tft.drawIcon(x, 0, *icon, color, w, h, 2);
  } else {
    IconColor color = icon->getColor();


    color.setForegroundColor(Palette::BLACK);
    color.setBackgroundColor(Palette::GRAY33);
    color.setNoBorder();


/*
    color.setForegroundColor(Palette::GRAY33);
    color.setBackgroundColor(Palette::GRAY33);
    color.setBorderColor(Palette::BLACK);
    */

    UI->tft.drawIcon(x, 0, *icon, color, w, h, 2);
  }
}



void Tab::drawLabel(uint16_t x, uint8_t w, uint8_t h) {
  TFT & tft = UI->tft;
  if (isSelected) {
    tft.setTextColor(COLOR_WHITE, COLOR_GRAY50);
  } else {
    tft.setTextColor(COLOR_BLACK, COLOR_GRAY33);
  }
  tft.setTextSize(2);
  tft.startTextFillBox(x, 0, w, h, 10, (h >> 1) - (uint8_t)6);
  if (label) {
    tft.print(label);
  }
  tft.finishTextFillBox();
}



