//
// Created by indrek on 13.04.2017.
//

#ifndef PBLOCKMAIN_TOOLBAR_H
#define PBLOCKMAIN_TOOLBAR_H

#include "TouchHandler.h"
#include "PageGrid.h"
#include "UiConstants.h"
#include "ToolBarButton.h"


class ToolBar : public Touchable {

    static const int8_t BUTTON_COUNT = 6;

    ToolBarButton button[BUTTON_COUNT];

public:
    static const uint16_t TOP = PageGrid::TOP + PageGrid::HEIGHT;
    static const uint16_t HEIGHT = SCREEN_HEIGHT - TOP;

    void init();
    void tap(uint16_t x, uint16_t y) override;
    void draw(bool redrawAll);


};


#endif //PBLOCKMAIN_TOOLBAR_H
