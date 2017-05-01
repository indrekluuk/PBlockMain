//
// Created by indrek on 10.04.2017.
//

#ifndef PBLOCKMAIN_SHEETS_H
#define PBLOCKMAIN_SHEETS_H

#include "TouchHandler.h"
#include "Tab.h"
#include "src/icons/ProgMemIcons.h"
#include "src/icons/Icon.h"



class Sheets : public Touchable {
    IconBufferProgMem playIcon = IconBufferProgMem(&ICON_PLAY);
    IconBufferProgMem modulesIcon = IconBufferProgMem(&ICON_MODULES);

    static const uint16_t SHEET_COUNT = 6;
    Tab tab[SHEET_COUNT];
    uint8_t index : 4;
    uint8_t drawnIndex : 4;

public:
    Sheets();
    void init();
    void tap(uint16_t x, uint16_t y, bool hold) override;

    void draw(bool redrawAll);
    void updateCursor();

private:
    void drawTabs(bool redrawAll);
    void drawSheet(bool redrawAll);


};


#endif //PBLOCKMAIN_SHEETS_H
