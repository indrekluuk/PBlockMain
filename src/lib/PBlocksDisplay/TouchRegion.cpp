//
// Created by indrek on 25.03.2017.
//

#include "TouchRegion.h"


TouchCallback * firstTouchCallback = nullptr;




TouchCallback::TouchCallback() {
  if (firstTouchCallback == nullptr) {
    firstTouchCallback = this;
  } else {
    TouchCallback * r = firstTouchCallback;
    while (r->nextRegion != nullptr) {
      r = r->nextRegion;
    }
    r->nextRegion = this;
  }
};


TouchCallback::~TouchCallback() {
  if (firstTouchCallback == this) {
    firstTouchCallback = this->nextRegion;
  } else if (firstTouchCallback != nullptr) {
    TouchCallback * r = firstTouchCallback;
    while (r->nextRegion != nullptr) {
      if (r->nextRegion == this) {
        r->nextRegion = this->nextRegion;
        return;
      }
      r = r->nextRegion;
    }
  }
}




