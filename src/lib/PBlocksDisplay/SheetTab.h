//
// Created by indrek on 29.03.2017.
//

#ifndef PBLOCKMAIN_SHEETTAB_H
#define PBLOCKMAIN_SHEETTAB_H

#include <stdint.h>
#include "IconBuffer.h"


class SheetTab {
public:
    const char * tabLabel = nullptr;
    IconBuffer * tabIcon = nullptr;

    void draw(uint16_t x, uint16_t w, uint16_t h, bool active);


private:
    void drawIcon(uint16_t x, uint16_t w, uint16_t h, bool active);
    void drawLabel(uint16_t x, uint16_t w, uint16_t h, bool active);

};



#endif //PBLOCKMAIN_SHEETTAB_H
