//
// Created by indrek on 25.03.2017.
//

#ifndef PBLOCKMAIN_PAGEGRIDFUNCTION_H
#define PBLOCKMAIN_PAGEGRIDFUNCTION_H


#include "PageGrid.h"
#include "src/program/PBlocksProgram.h"





class PageGridFunction : public PageGrid {


public:


    PageGridFunction(ProgramFunction & f) : function(f) {};
    void draw(bool redrawAll);
    void setActiveNode(uint8_t col, uint8_t row);
    void updateCursor();

private:

    void drawSlot(uint8_t col, uint8_t row);
    void drawProgramSlot(uint8_t col, uint8_t row, ProgramNode * node, bool isActive);





    ProgramFunction & function;

/*


    void setSelected(bool isSelected);
    bool isSelected();


private:


    void drawSheet(bool redrawAll);
    void drawCursor(uint16_t slotX, uint16_t slotY, uint8_t index);


    uint16_t getSlotXByIndex(uint8_t index);
    uint16_t getSlotYByIndex(uint8_t index);
*/
};


#endif //PBLOCKMAIN_PAGEGRIDFUNCTION_H
