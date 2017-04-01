//
// Created by indrek on 25.03.2017.
//

#ifndef PBLOCKMAIN_SHEET_H
#define PBLOCKMAIN_SHEET_H


#include <stdint.h>
#include <IconBuffer.h>
#include "TouchHandler.h"


class PBlocksDisplay;


class Sheet : public Touchable {

    static const uint16_t TAB_HEIGHT = 50;
    static const uint16_t TAB_WIDTH = 80;

    static const uint8_t SLOT_COL_COUNT = 6;
    static const uint8_t SLOT_ROW_COUNT = 3;
    static const uint8_t SLOT_COUNT = SLOT_COL_COUNT * SLOT_ROW_COUNT;

    static const uint16_t SLOT_SPACING_V = 6;
    static const uint16_t SLOT_SPACING_H = 16;
    static const uint8_t SLOT_WIDTH = 60;
    static const uint8_t SLOT_HEIGHT = 60;
    static const uint16_t SHEET_HEIGHT = SLOT_ROW_COUNT * (SLOT_HEIGHT + SLOT_SPACING_V) + SLOT_SPACING_V + 6;


    uint8_t tabIndex : 4;
    bool selected : 1;
    bool isDrawnAsSelected : 3;

public:
    const char * tabLabel = nullptr;
    IconBuffer * tabIcon = nullptr;

    Sheet();

    void init(uint8_t index);
    void tap(uint16_t x, uint16_t y) override ;

    void setSelected(bool isSelected);
    bool isSelected();

    void draw(bool redrawAll);
private:

    void drawTab(bool redrawAll);
    void drawTabIcon(uint16_t x, uint8_t w, uint8_t h);
    void drawTabLabel(uint16_t x, uint8_t w, uint8_t h);

    void drawSheet(bool redrawAll);
    void drawProgramSlot(uint8_t index, uint16_t x, uint16_t y);

    uint16_t getTabX();

};


#endif //PBLOCKMAIN_SHEET_H
