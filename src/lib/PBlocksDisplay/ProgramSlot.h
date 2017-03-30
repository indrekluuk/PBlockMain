//
// Created by indrek on 25.03.2017.
//

#ifndef PBLOCKMAIN_PROGRAMSLOT_H
#define PBLOCKMAIN_PROGRAMSLOT_H


#include "stdint.h"


class ProgramSlot {

    uint16_t x = 0;
    uint16_t y = 0;

public:
    static const uint8_t WIDTH = 60;
    static const uint8_t HEIGHT = 60;

    void init(uint16_t x, uint16_t y);

    void draw();

};


#endif //PBLOCKMAIN_PROGRAMSLOT_H
