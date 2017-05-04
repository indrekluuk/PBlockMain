//
// Created by indrek on 13.04.2017.
//

#ifndef PBLOCKMAIN_TOOLBARBUTTON_H
#define PBLOCKMAIN_TOOLBARBUTTON_H


#include <stdint.h>
#include "PageGrid.h"
#include "UiConstants.h"



class ToolBarButton {
    static const uint16_t DECORATION_TYPE_NONE = 0;
    static const uint16_t DECORATION_TYPE_ICON = 1;
    static const uint16_t DECORATION_TYPE_LABEL = 2;


public:
    static const uint16_t TOP = PageGrid::TOP + PageGrid::HEIGHT;
    static const uint16_t HEIGHT = SCREEN_HEIGHT - TOP;
    static const uint16_t WIDTH = 60;


    void init(uint8_t index);
    void init(uint8_t index, Icon * icon);
    void init(uint8_t index, const char * label);
    void draw(bool isPressed);


private:
    void drawIcon(uint16_t x, uint16_t y, uint8_t w, uint8_t h, bool isPressed);
    void drawLabel(uint16_t x, uint16_t y, uint8_t w, uint8_t h, bool isPressed);

    const void * decoration = nullptr;
    uint8_t index : 4;
    uint8_t decorationType : 4;


};


#endif //PBLOCKMAIN_TOOLBARBUTTON_H
