//
// Created by indrek on 25.03.2017.
//

#include <Arduino.h>
#include "TouchHandler.h"
#include "PBlocksDisplay.h"

Touchable * firstTouchable = nullptr;




Touchable::Touchable() {
  if (firstTouchable == nullptr) {
    firstTouchable = this;
  } else {
    Touchable * touchable = firstTouchable;
    while (touchable->nextRegion != nullptr) {
      touchable = touchable->nextRegion;
    }
    touchable->nextRegion = this;
  }
};


Touchable::~Touchable() {
  if (firstTouchable == this) {
    firstTouchable = this->nextRegion;
  } else if (firstTouchable != nullptr) {
    Touchable * touchable = firstTouchable;
    while (touchable->nextRegion != nullptr) {
      if (touchable->nextRegion == this) {
        touchable->nextRegion = this->nextRegion;
        return;
      }
      touchable = touchable->nextRegion;
    }
  }
}



bool Touchable::isTapIn(int16_t v, int16_t start, int16_t length) {
  return isTapBetween(v, start, start+length);
}

bool Touchable::isTapBetween(int16_t v, int16_t begin, int16_t end) {
  return (v > begin) && (v < end);
}




uint8_t TouchHandler::getRegionCount() {
  uint8_t count = 0;
  Touchable * touchable = firstTouchable;
  while(touchable != nullptr) {
    count++;
    touchable = touchable->nextRegion;
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

    Touchable * touchable = firstTouchable;
    while(touchable != nullptr) {
      touchable->tap(x, y);
      touchable = touchable->nextRegion;
    }
  }
}



void TouchHandler::readResistiveTouch() {
  tp = touchScreen.getPoint();
  pinMode(YP, OUTPUT);      //restore shared pins
  pinMode(XM, OUTPUT);
  digitalWrite(YP, HIGH);   //because TFT control pins
  digitalWrite(XM, HIGH);
}



