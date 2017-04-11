//
// Created by indrek on 7.04.2017.
//

#ifndef PBLOCKMAIN_TAB_H
#define PBLOCKMAIN_TAB_H


#include <stdint.h>
#include "src/icons/Icon.h"


struct Tab {

    static const uint16_t DECORATION_TYPE_ICON = 0;
    static const uint16_t DECORATION_TYPE_LABEL = 1;

public:
    static const uint16_t HEIGHT = 50;
    static const uint16_t WIDTH = 80;


    void init(uint8_t index, Icon * icon);
    void init(uint8_t index, const char * label);
    uint16_t getTabX1();
    uint16_t getTabX2();
    void draw(bool isSelected);

private:
    void drawIcon(uint16_t x, uint8_t w, uint8_t h, bool isSelected);
    void drawLabel(uint16_t x, uint8_t w, uint8_t h, bool isSelected);

    const void * decoration = nullptr;
    uint8_t index : 4;
    uint8_t decorationType : 4;
};


#endif //PBLOCKMAIN_TAB_H
