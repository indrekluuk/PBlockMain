//
// Created by indrek on 25.03.2017.
//

#ifndef PBLOCKMAIN_PBLOCKSUSER_INTERFACE_H
#define PBLOCKMAIN_PBLOCKSUSER_INTERFACE_H


#include "Sheets.h"
#include "TouchHandler.h"
#include "src/screen/TFT.h"


class PBlocksUserInterface {
public:
    TFT tft;
    Sheets sheets;
    TouchHandler touchHandler;

    PBlocksUserInterface();
    void init();

    void draw(bool redrawAll);
    void run();

};


extern PBlocksUserInterface * UI;

#endif //PBLOCKMAIN_PBLOCKSUSER_INTERFACE_H
