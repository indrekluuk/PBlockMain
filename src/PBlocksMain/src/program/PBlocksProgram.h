//
// Created by indrek on 1.04.2017.
//

#ifndef PBLOCKMAIN_PBLOCKSPROGRAM_H
#define PBLOCKMAIN_PBLOCKSPROGRAM_H


#include "ProgramFunction.h"
#include "Module.h"
#include "../display/ProgMemIcons.h"


class PBlocksProgram {

    IconBufferProgMem icon1 = IconBufferProgMem(&ICON_PERSON);
    IconBufferProgMem icon2 = IconBufferProgMem(&ICON_PLAY);

    static const uint8_t FUNCTION_COUNT = 5;
    ProgramFunction functions[FUNCTION_COUNT];

public:
    static const uint8_t MODULE_NONE = 0xF;
    Module modules[2] = {Module(icon1), Module(icon2)};


    PBlocksProgram();
    ProgramFunction * getFunction(uint8_t index);

};



extern PBlocksProgram * Program;


#endif //PBLOCKMAIN_PBLOCKSPROGRAM_H
