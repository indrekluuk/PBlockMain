//
// Created by indrek on 1.04.2017.
//

#ifndef PBLOCKMAIN_PROGRAMNODE_H
#define PBLOCKMAIN_PROGRAMNODE_H


#include <stdint.h>
#include "Module.h"


class ProgramNode {

    uint8_t module : 4;
    uint8_t reserved : 4;

public:

    ProgramNode();

    bool isEmpty();
    Module * getModule();
    void setModule(uint8_t moduleIndex);

};


#endif //PBLOCKMAIN_PROGRAMNODE_H
