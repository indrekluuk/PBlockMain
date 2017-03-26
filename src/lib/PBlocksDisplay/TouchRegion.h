//
// Created by indrek on 25.03.2017.
//

#ifndef PBLOCKMAIN_TOUCHREGION_H
#define PBLOCKMAIN_TOUCHREGION_H

#include <Arduino.h>
#include <stdint.h>



class TouchCallback {
public:
    TouchCallback();
    ~TouchCallback();
    virtual void tap(uint16_t x, uint16_t y) = 0;
    TouchCallback * nextRegion = nullptr;
};


template<class TObj>
class TouchRegion : public TouchCallback {

public:
    typedef void (TObj::*CallbackMethod)(void);

private:

    TObj* callbackObj = nullptr;
    CallbackMethod callbackMethod = nullptr;

    uint16_t x = 0;
    uint16_t y = 0;
    uint8_t w = 0;
    uint8_t h = 0;

public:

    void init(
        uint16_t x,
        uint16_t y,
        uint8_t w,
        uint8_t h,
        TObj * obj,
        CallbackMethod callbackMethod);

    void tap(uint16_t x, uint16_t y);
};



template<class TObj>
void TouchRegion<TObj>::init(
    uint16_t x,
    uint16_t y,
    uint8_t w,
    uint8_t h,
    TObj * obj,
    CallbackMethod method
) {
  this->x = x;
  this->y = y;
  this->w = w;
  this->h = h;
  this->callbackObj = obj;
  this->callbackMethod = method;
}



template<class TObj>
void TouchRegion<TObj>::tap(uint16_t x, uint16_t y) {
  if (
      (x > this->x)
      && (x < this->x + this->w)
      && (y > this->y)
      && (y < this->y + this->h)
      ) {
    (callbackObj->*callbackMethod)();
  }
}





#endif //PBLOCKMAIN_TOUCHREGION_H
