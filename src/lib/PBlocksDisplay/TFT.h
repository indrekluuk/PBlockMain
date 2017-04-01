//
// Created by indrek on 26.03.2017.
//

#ifndef PBLOCKMAIN_TFT_H
#define PBLOCKMAIN_TFT_H


#include <MCUFRIEND_kbv.h>
#include <utility/mcufriend_shield.h>
#include <IconBuffer.h>


class TFT : public MCUFRIEND_kbv {

private:
    // _MW is private in MCUFRIEND_kbv.h
    uint16_t _MW = 0x2C;

public:
    void drawIcon(uint16_t x, uint16_t y, IconBuffer & icon, IconColor iconColor, uint8_t w, uint8_t h, uint8_t scale);

private:
    void write8bitmap(
        RgbColor color,
        RgbColor bgColor,
        uint16_t bitmap,
        uint8_t scale);

    void write8bitmapWithBorder(
        RgbColor color,
        RgbColor bgColor,
        RgbColor bTopColor,
        RgbColor bBottomColor,
        uint16_t prvBitmap,
        uint16_t curBitmap,
        uint16_t nxtBitmap,
        uint8_t scale);

    void writeColorN(RgbColor color, uint16_t n);


};



#endif //PBLOCKMAIN_TFT_H
