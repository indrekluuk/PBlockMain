//
// Created by indrek on 26.03.2017.
//

#ifndef PBLOCKMAIN_ICONBUFFER_H
#define PBLOCKMAIN_ICONBUFFER_H


#include <stdint.h>
#include "Colors.h"




struct IconColor {
    uint8_t drawColor : 4;
    uint8_t backgroundColor : 4;
    uint8_t borderColor : 4;
    uint8_t hasBorder : 1;
    uint8_t hasBorder3d : 1;
    uint8_t reserved : 2;

    IconColor() {
      drawColor = Palette::WHITE;
      backgroundColor = Palette::BLACK;
      borderColor = Palette::BLACK;
      hasBorder = false;
      hasBorder3d = false;
      reserved = 0;
    }

    void setDrawColor(Palette p) {drawColor = p;};
    void setBackgroundColor(Palette p) {backgroundColor = p;};
    void setBorderColor(Palette p) {borderColor = p; hasBorder = true; hasBorder3d = false; };
    void setBorder3d() {hasBorder = true; hasBorder3d = true; };
    void setNoBorder() {hasBorder = false;}

    RgbColor getDrawColor() { return RgbColor((Palette)drawColor); }
    RgbColor getBackgroundColor() { return RgbColor((Palette)backgroundColor); }
    RgbColor getBorderColor() { return RgbColor((Palette)borderColor); }
};




class IconBuffer {

public:
    static const uint8_t BITMAP_WIDTH = 16;
    static const uint8_t BITMAP_HEIGHT = 16;

    IconColor color;
    uint16_t bitmap[BITMAP_HEIGHT];

    void setBitmap(uint8_t index, uint16_t row) {bitmap[index] = row; }
};


#endif //PBLOCKMAIN_ICONBUFFER_H
