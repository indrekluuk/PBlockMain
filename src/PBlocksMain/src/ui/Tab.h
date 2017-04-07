//
// Created by indrek on 7.04.2017.
//

#ifndef PBLOCKMAIN_TAB_H
#define PBLOCKMAIN_TAB_H


#include <stdint.h>
#include "src/icons/Icon.h"


struct Tab {

    static const uint16_t HEIGHT = 50;
    static const uint16_t WIDTH = 80;

    uint8_t index : 4;
    bool isSelected : 1;
    bool isDrawnAsSelected : 3;

    const char * label = nullptr;
    Icon * icon = nullptr;

    Tab();

    uint16_t getTabX();

    bool needsRedraw() { return isDrawnAsSelected != isSelected; }
    void draw(bool redrawAll);
    void drawIcon(uint16_t x, uint8_t w, uint8_t h);
    void drawLabel(uint16_t x, uint8_t w, uint8_t h);
    void drawingDone() { isDrawnAsSelected = isSelected; }


};


#endif //PBLOCKMAIN_TAB_H
