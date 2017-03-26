//
// Created by indrek on 25.03.2017.
//

#include <Arduino.h>
#include "TouchHandler.h"
#include "PBlocksDisplay.h"


extern TouchCallback * firstTouchCallback;



uint8_t TouchHandler::getRegionCount() {
  uint8_t count = 0;
  TouchCallback * r = firstTouchCallback;
  while(r != nullptr) {
    count++;
    r = r->nextRegion;
  }
  return count;
}


#define TOUCH_LEFT 950
#define TOUCH_RIGHT 139
#define TOUCH_TOP 123
#define TOUCH_BOTTOM 915



void TouchHandler::check() {
  MCUFRIEND_kbv & tft = PBlocksDisplay::tft;

  readResistiveTouch();
  if (tp.z > 100) {
    uint16_t x = map(tp.y, TOUCH_LEFT, TOUCH_RIGHT, 0, tft.width());
    uint16_t y = map(tp.x, TOUCH_TOP, TOUCH_BOTTOM, 0, tft.height());

    TouchCallback * r = firstTouchCallback;
    while(r != nullptr) {
      r->tap(x, y);
      r = r->nextRegion;
    }
    /*
    if (isPos(tp.y, 880)) display.setActiveTab(0);
    if (isPos(tp.y, 740)) display.setActiveTab(1);
    if (isPos(tp.y, 600)) display.setActiveTab(2);
    if (isPos(tp.y, 460)) display.setActiveTab(3);
    if (isPos(tp.y, 320)) display.setActiveTab(4);
    if (isPos(tp.y, 170)) display.setActiveTab(5);
    display.draw(false);
     */
  }
}



void TouchHandler::readResistiveTouch() {
  tp = touchScreen.getPoint();
  pinMode(YP, OUTPUT);      //restore shared pins
  pinMode(XM, OUTPUT);
  digitalWrite(YP, HIGH);   //because TFT control pins
  digitalWrite(XM, HIGH);
}



