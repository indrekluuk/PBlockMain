//
// Created by indrek on 26.03.2017.
//

#ifndef PBLOCKMAIN_ICONBUFFER_H
#define PBLOCKMAIN_ICONBUFFER_H


#include <avr/pgmspace.h>
#include <stdint.h>
#include "src/display/Colors.h"





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



class IconBufferProgMem : public IconBuffer {
public:
    struct Icon {
        IconColor color;
        uint16_t bitmap[BITMAP_HEIGHT];
    };

private:
    const Icon * pData;

public:

    IconBufferProgMem(const Icon * pData) : pData(pData) {};

    IconColor getColor() override {
        return (IconColor)pgm_read_word_near(&(pData->color));
    }
    uint16_t getRow(uint8_t index) override {
        return pgm_read_word_near(&(pData->bitmap[index]));
    };
};




#endif //PBLOCKMAIN_ICONBUFFER_H
