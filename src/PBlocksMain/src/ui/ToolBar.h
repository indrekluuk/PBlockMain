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

    static const uint8_t BUTTON_COUNT = 6;
    static const uint8_t NONE = BUTTON_COUNT;

    ToolBarButton button[BUTTON_COUNT];
    uint8_t activeButtonIndex : 4;
    uint8_t pressedButtonIndex : 4;
    uint8_t drawnAsPressedIndex : 4;
    uint8_t resrv : 4;

public:
    static const uint16_t TOP = ToolBarButton::TOP;
    static const uint16_t HEIGHT = ToolBarButton::HEIGHT;

    ToolBar();
    void init();
    void tap(uint16_t x, uint16_t y, bool hold) override;
    uint8_t getTappedButtonIndex(uint16_t x, uint16_t y);
    void draw(bool redrawAll);


};


#endif //PBLOCKMAIN_TOOLBAR_H