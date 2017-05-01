//
// Created by indrek on 13.04.2017.
//

#ifndef PBLOCKMAIN_TOOLBARBUTTON_H
#define PBLOCKMAIN_TOOLBARBUTTON_H


#include <stdint.h>
#include "PageGrid.h"
#include "UiConstants.h"



class ToolBarButton {


    uint8_t index;

public:
    static const uint16_t TOP = PageGrid::TOP + PageGrid::HEIGHT;
    static const uint16_t HEIGHT = SCREEN_HEIGHT - TOP;
    static const uint16_t WIDTH = 80;



    void init(uint8_t buttonIndex);
    void draw(bool isPressed);

};


#endif //PBLOCKMAIN_TOOLBARBUTTON_H
