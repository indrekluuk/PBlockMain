//
// Created by indrek on 13.04.2017.
//

#include "ToolBarButton.h"
#include "PBlocksUserInterface.h"



void ToolBarButton::init(uint8_t tabIndex) {
  index = tabIndex;
  decorationType = DECORATION_TYPE_NONE;
  decoration = nullptr;
}


void ToolBarButton::init(uint8_t tabIndex, Icon *icon) {
  index = tabIndex;
  decorationType = DECORATION_TYPE_ICON;
  decoration = icon;
}


void ToolBarButton::init(uint8_t tabIndex, const char *label) {
  index = tabIndex;
  decorationType = DECORATION_TYPE_LABEL;
  decoration = label;
}




void ToolBarButton::draw(bool isPressed) {
  TFT &tft = UI->tft;

  tft.drawFastHLine(index*WIDTH, TOP, WIDTH, isPressed ? COLOR_GRAY33 : COLOR_WHITE);
  tft.drawFastVLine(index*WIDTH, TOP, HEIGHT, isPressed ? COLOR_GRAY33 : COLOR_WHITE);
  tft.drawFastHLine(index*WIDTH, TOP + HEIGHT - 1, WIDTH, isPressed ? COLOR_WHITE : COLOR_GRAY33);
  tft.drawFastVLine(index*WIDTH + WIDTH - 1, TOP, HEIGHT, isPressed ? COLOR_WHITE : COLOR_GRAY33);


  uint16_t x = index * WIDTH + (uint16_t)1;
  uint16_t y = TOP+1;
  uint8_t w = WIDTH - 2;
  uint8_t h = HEIGHT - 2;

  if (decorationType == DECORATION_TYPE_ICON) {
    drawIcon(x, y, w, h, isPressed);
  } else if (decorationType == DECORATION_TYPE_LABEL) {
    drawLabel(x, y, w, h, isPressed);
  } else {
    tft.fillRect(x, y, w, h, isPressed ? COLOR_GRAY66 : COLOR_GRAY85);
  }

}







void ToolBarButton::drawIcon(uint16_t x, uint16_t y, uint8_t w, uint8_t h, bool isPressed) {
  Icon *icon = (Icon*) decoration;

  if (isPressed) {
    IconColor color = icon->getColor();

    color.setForegroundColor(Palette::DARK_GREEN);
    color.setBackgroundColor(Palette::GRAY85);
    //color.setBorderColor(Palette::BLACK);
    color.setNoBorder();

    UI->tft.drawIcon(x, y, *icon, color, w, h, 2, 2, 2);
  } else {
    IconColor color = icon->getColor();

    color.setForegroundColor(Palette::DARK_GREEN);
    color.setBackgroundColor(Palette::GRAY66);
    //color.setBorderColor(Palette::BLACK);
    color.setNoBorder();

    UI->tft.drawIcon(x, y, *icon, color, w, h, 0, 0, 2);
  }
}





void ToolBarButton::drawLabel(uint16_t x, uint16_t y, uint8_t w, uint8_t h, bool isPressed) {
  const char *label = (const char *)decoration;

  TFT & tft = UI->tft;
  if (isPressed) {
    tft.setTextColor(COLOR_WHITE, COLOR_GRAY85);
  } else {
    tft.setTextColor(COLOR_WHITE, COLOR_GRAY66);
  }
  tft.setTextSize(2);

  uint8_t cX = 10;
  uint8_t cY = (h >> 1) - (uint8_t)6;
  if (isPressed) {
    cX+=2;
    cY+=2;
  }
  tft.startTextFillBox(x, y, w, h, cX, cY);
  if (label) {
    tft.print(label);
  }
  tft.finishTextFillBox();
}


