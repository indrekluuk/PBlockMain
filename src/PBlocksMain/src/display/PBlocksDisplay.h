//
// Created by indrek on 25.03.2017.
//

#ifndef PBLOCKMAIN_PBLOCKSDISPLAY_H
#define PBLOCKMAIN_PBLOCKSDISPLAY_H


#include "Sheet.h"
#include "src/icons/ProgMemIcons.h"
#include "src/icons/IconBuffer.h"
#include "TouchHandler.h"
#include "TFT.h"


class PBlocksDisplay {
    static const uint16_t SHEET_COUNT = 6;

    IconBufferProgMem playIcon = IconBufferProgMem(&ICON_PLAY);
    IconBufferProgMem modulesIcon = IconBufferProgMem(&ICON_MODULES);
    Sheet sheets[SHEET_COUNT];

public:
    PBlocksDisplay();

    void init();
    void setActiveTab(uint16_t tabIndex);

    void draw(bool redrawAll);
    void updateSheets(bool redrawAll);
    void updateCursor();

    TFT tft;
    TouchHandler touchHandler;
};


extern PBlocksDisplay * Display;

#endif //PBLOCKMAIN_PBLOCKSDISPLAY_H