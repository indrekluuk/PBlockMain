//
// Created by indrek on 25.03.2017.
//

#ifndef PBLOCKMAIN_PBLOCKSUSER_INTERFACE_H
#define PBLOCKMAIN_PBLOCKSUSER_INTERFACE_H


#include "Sheet.h"
#include "src/icons/ProgMemIcons.h"
#include "src/icons/Icon.h"
#include "TouchHandler.h"
#include "src/screen/TFT.h"


class PBlocksUserInterface {
    static const uint16_t SHEET_COUNT = 6;

    IconBufferProgMem playIcon = IconBufferProgMem(&ICON_PLAY);
    IconBufferProgMem modulesIcon = IconBufferProgMem(&ICON_MODULES);
    Sheet sheets[SHEET_COUNT];

public:
    PBlocksUserInterface();

    void init();
    void setActiveTab(uint16_t tabIndex);

    void draw(bool redrawAll);
    void updateSheets(bool redrawAll);
    void updateCursor();

    TFT tft;
    TouchHandler touchHandler;
};


extern PBlocksUserInterface * Display;

#endif //PBLOCKMAIN_PBLOCKSUSER_INTERFACE_H
