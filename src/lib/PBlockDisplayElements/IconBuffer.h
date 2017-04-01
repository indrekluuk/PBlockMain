//
// Created by indrek on 26.03.2017.
//

#ifndef PBLOCKMAIN_ICONBUFFER_H
#define PBLOCKMAIN_ICONBUFFER_H


#include <stdint.h>
#include "Colors.h"





class IconBuffer {
public:
    static const uint8_t BITMAP_WIDTH = 16;
    static const uint8_t BITMAP_HEIGHT = 16;

    virtual IconColor getColor() = 0;
    virtual uint16_t getRow(uint8_t index) = 0;
};




class IconBufferMem : public IconBuffer {
public:
    IconColor color;
    uint16_t bitmap[BITMAP_HEIGHT];

    IconColor getColor() override {return color; }
    uint16_t getRow(uint8_t index) override {return bitmap[index];};
};






#endif //PBLOCKMAIN_ICONBUFFER_H
