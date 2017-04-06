//
// Created by indrek on 25.03.2017.
//

#ifndef PBLOCKMAIN_PBLOCKSMAINMODULE_H
#define PBLOCKMAIN_PBLOCKSMAINMODULE_H


#include "src/program/PBlocksProgram.h"
#include "src/display/PBlocksDisplay.h"



class PBlocksMainModule {


    PBlocksProgram program;
    PBlocksDisplay display;

public:
    void init();

    void run();

};


#endif //PBLOCKMAIN_PBLOCKSMAINMODULE_H
