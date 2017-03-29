//
// Created by indrek on 25.03.2017.
//

#ifndef PBLOCKMAIN_SHEET_H
#define PBLOCKMAIN_SHEET_H


#include <stdint.h>
#include "SheetTab.h"
#include "TouchHandler.h"


class PBlocksDisplay;


class Sheet : public Touchable {

    static const uint16_t TAB_HEIGHT = 60;
    static const uint16_t TAB_WIDTH = 80;
    static const uint16_t SHEET_HEIGHT = 200;

    uint8_t tabIndex : 4;
    bool selected : 1;
    bool isDrawnAsSelected : 3;

public:
    SheetTab tab;

    Sheet();

    void init(uint8_t index);
    void tap(uint16_t x, uint16_t y) override ;

    void setSelected(bool isSelected);
    bool isSelected();

    void draw(bool redrawAll);
    void drawTab(bool redrawAll);
    void drawSheet(bool redrawAll);

private:
    uint16_t getTabX();

};


#endif //PBLOCKMAIN_SHEET_H
