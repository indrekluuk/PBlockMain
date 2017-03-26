//
// Created by indrek on 25.03.2017.
//

#ifndef PBLOCKMAIN_SHEET_H
#define PBLOCKMAIN_SHEET_H


#include <stdint.h>
#include "MCUFRIEND_kbv.h"
#include "TouchRegion.h"


class PBlocksDisplay;


class Sheet {

    static const uint16_t TAB_HEIGHT = 60;
    static const uint16_t SHEET_HEIGHT = 200;

    int8_t tabIndex = -1;
    int16_t tabX = 0;
    int16_t tabW = 0;
    bool selected = false;
    bool isDrawnAsSelected = false;
    TouchRegion<Sheet> tabTouchRegion;

    PBlocksDisplay * display = nullptr;
    MCUFRIEND_kbv & tft;
public:
    Sheet();

    void init(PBlocksDisplay * display, int8_t tabIndex, int16_t tabX, int16_t tabW);

    void setSelected(bool isSelected);
    bool isSelected();

    void draw(bool redrawAll);
    void drawTab(bool redrawAll);
    void drawSheet(bool redrawAll);


private:
    void tabClicked();


};


#endif //PBLOCKMAIN_SHEET_H
