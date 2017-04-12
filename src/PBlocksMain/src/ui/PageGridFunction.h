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
    void updateCursor();
    void tap(uint16_t x, uint16_t y);


private:
    void setActiveNode(uint8_t col, uint8_t row);
    void drawSlot(uint8_t col, uint8_t row);
    void drawProgramSlot(uint8_t col, uint8_t row, ProgramNode * node, bool isActive);

    ProgramFunction & function;

};


#endif //PBLOCKMAIN_PAGEGRIDFUNCTION_H
