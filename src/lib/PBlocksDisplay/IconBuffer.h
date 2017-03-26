//
// Created by indrek on 26.03.2017.
//

#ifndef PBLOCKMAIN_ICONBUFFER_H
#define PBLOCKMAIN_ICONBUFFER_H


#include <stdint.h>


class IconBuffer {

public:
    static const uint16_t BITMAP_WIDTH = 16;
    static const uint16_t BITMAP_HEIGHT = 16;

    uint8_t width;
    uint8_t height;
    uint16_t color;
    uint16_t bgColor;

    uint8_t bitmapX;
    uint8_t bitmapY;
    uint16_t bitmap[BITMAP_HEIGHT];
    uint8_t scale = 2;

    IconBuffer(uint8_t w, uint8_t h, uint8_t bX, uint8_t bY, uint16_t color, uint16_t bgColor) :
        width(w),
        height(h),
        color(color),
        bgColor(bgColor),
        bitmapX(bX),
        bitmapY(bY) {};

    const uint16_t getBitmapX2() {return bitmapX + BITMAP_WIDTH * scale;}
    const uint16_t getBitmapY2() {return bitmapY + BITMAP_HEIGHT * scale;}

    void setBitmap(uint8_t index, uint16_t row) {bitmap[index] = row; }

};


#endif //PBLOCKMAIN_ICONBUFFER_H
