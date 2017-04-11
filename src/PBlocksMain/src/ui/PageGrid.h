//
// Created by indrek on 11.04.2017.
//

#ifndef PBLOCKMAIN_PAGEGRID_H
#define PBLOCKMAIN_PAGEGRID_H

#include <stdint.h>



class PBlocksUserInterface;



class PageGrid {

protected:

    static const uint16_t SLOT_SPACING = 6;
    static uint16_t slotAreaWidth;

public:
    static const uint8_t SLOT_COL_COUNT = 6;
    static const uint8_t SLOT_ROW_COUNT = 3;
    static const uint8_t SLOT_WIDTH = 68;
    static const uint8_t SLOT_HEIGHT = 60;
    static const uint16_t SHEET_HEIGHT = SLOT_ROW_COUNT * (SLOT_HEIGHT + SLOT_SPACING) + SLOT_SPACING * 2;

    static void staticInit(uint16_t sheetW);


    static uint16_t getSlotX(uint8_t col);
    static uint16_t getSlotY(uint8_t row);
    static uint8_t getSlotIndex(uint8_t col, uint8_t row);
    static uint8_t getSlotCol(uint8_t index);
    static uint8_t getSlotRow(uint8_t index);

protected:
    void clearPage();
    void drawEmptySlot(uint8_t col, uint8_t row, uint16_t cursorColor);
    void drawCursor(uint16_t slotX, uint16_t slotY, uint16_t color);
    uint16_t getCursorColor(bool isActive);




};


#endif //PBLOCKMAIN_PAGEGRID_H
