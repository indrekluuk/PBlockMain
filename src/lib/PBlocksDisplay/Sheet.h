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

    static const uint16_t SLOT_SPACING = 6;
    static const uint8_t SLOT_WIDTH = 68;
    static const uint8_t SLOT_HEIGHT = 60;
    static uint16_t slotAreaWidth;
    static const uint16_t SHEET_HEIGHT = SLOT_ROW_COUNT * (SLOT_HEIGHT + SLOT_SPACING) + SLOT_SPACING * 2;


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
    void updateCursor();

private:

    void setActiveNode(uint16_t x, uint16_t y, uint8_t index);

    void drawTab(bool redrawAll);
    void drawTabIcon(uint16_t x, uint8_t w, uint8_t h);
    void drawTabLabel(uint16_t x, uint8_t w, uint8_t h);

    void drawSheet(bool redrawAll);
    void drawCursor(uint16_t slotX, uint16_t slotY, uint8_t index);
    void drawEmptySlot(uint16_t x, uint16_t y);
    void drawProgramSlot(uint16_t x, uint16_t y, uint8_t index);

    uint16_t getTabX();

    uint8_t getSlotIndex(uint8_t col, uint8_t row);
    uint16_t getSlotXByIndex(uint8_t index);
    uint16_t getSlotYByIndex(uint8_t index);
    uint16_t getSlotX(uint8_t col);
    uint16_t getSlotY(uint8_t row);

};


#endif //PBLOCKMAIN_SHEET_H
