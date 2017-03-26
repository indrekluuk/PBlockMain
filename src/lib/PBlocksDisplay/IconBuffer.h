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

    uint8_t width = 0;
    uint8_t height = 0;
    uint16_t color = 0;

    uint8_t bitmapX = 0;
    uint8_t bitmapY = 0;
    uint16_t bitmap[BITMAP_HEIGHT];
    uint8_t scale = 2;

    IconBuffer() {}

    IconBuffer(uint8_t w, uint8_t h, uint8_t bX, uint8_t bY, uint16_t color) :
        width(w),
        height(h),
        color(color),
        bitmapX(bX),
        bitmapY(bY) {};

    const uint16_t getBitmapX2() {return bitmapX + BITMAP_WIDTH * scale;}
    const uint16_t getBitmapY2() {return bitmapY + BITMAP_HEIGHT * scale;}

    void setBitmap(uint8_t index, uint16_t row) {bitmap[index] = row; }

    void bitmapCenterX() {bitmapX = width/2 - (BITMAP_WIDTH*scale/2);};
    void bitmapCenterY() {bitmapY = height/2 - (BITMAP_HEIGHT*scale/2);};

};


#endif //PBLOCKMAIN_ICONBUFFER_H
