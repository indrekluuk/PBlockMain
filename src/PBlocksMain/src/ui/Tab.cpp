//
// Created by indrek on 7.04.2017.
//

#include "Tab.h"
#include "PBlocksUserInterface.h"



void Tab::init(uint8_t tabIndex, Icon *icon) {
  index = tabIndex;
  decorationType = DECORATION_TYPE_ICON;
  decoration = icon;
}


void Tab::init(uint8_t tabIndex, const char *label) {
  index = tabIndex;
  decorationType = DECORATION_TYPE_LABEL;
  decoration = label;
}


uint16_t Tab::getTabX1() {
  return index * WIDTH;
}

uint16_t Tab::getTabX2() {
  return getTabX1() + WIDTH;
}


void Tab::draw(bool isSelected) {
  uint16_t x = getTabX1() + (uint16_t)1;
  uint8_t w = WIDTH - 2;

  UI->tft.drawFastHLine(x , HEIGHT - 1 , w, isSelected ? COLOR_GRAY50 : COLOR_BLACK);
  if (decorationType == DECORATION_TYPE_ICON) {
    drawIcon(x, w, HEIGHT - 1, isSelected);
  } else if (decorationType == DECORATION_TYPE_LABEL) {
    drawLabel(x, w, HEIGHT - 1, isSelected);
  } else {
    UI->tft.fillRect(x, 0, w, HEIGHT - 1, isSelected ? COLOR_GRAY50 : COLOR_GRAY33);
  }
}



void Tab::drawIcon(uint16_t x, uint8_t w, uint8_t h, bool isSelected) {
  Icon *icon = (Icon*) decoration;

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



void Tab::drawLabel(uint16_t x, uint8_t w, uint8_t h, bool isSelected) {
  const char *label = (const char *)decoration;

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



