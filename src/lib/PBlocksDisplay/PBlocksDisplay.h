//
// Created by indrek on 25.03.2017.
//

#ifndef PBLOCKMAIN_PBLOCKSDISPLAY_H
#define PBLOCKMAIN_PBLOCKSDISPLAY_H


#include "Sheet.h"


class PBlocksDisplay {

    static const uint16_t SHEET_COUNT = 6;
    static const uint16_t TAB_WIDTH = 80;



    Sheet sheets[SHEET_COUNT];

public:


    void init();

    void setActiveTab(uint16_t tabIndex);

    void draw(bool redrawAll);
    void updateSheets(bool redrawAll);

};


#endif //PBLOCKMAIN_PBLOCKSDISPLAY_H
