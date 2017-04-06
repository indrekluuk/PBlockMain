//
// Created by indrek on 1.04.2017.
//

#ifndef PBLOCKMAIN_PROGRAMFUNCTION_H
#define PBLOCKMAIN_PROGRAMFUNCTION_H


#include "ProgramNode.h"



class ProgramFunction {

    static const uint8_t NODE_COUNT = 18;
    ProgramNode nodes[NODE_COUNT];

    uint8_t activeNodeIndex;

public:

    ProgramFunction();

    ProgramNode * getNode(uint8_t index);

    uint8_t setActiveNode(uint8_t index);
    void activateLast();

    uint8_t getActiveNodeIndex();
    ProgramNode * getActiveNode();

};


#endif //PBLOCKMAIN_PROGRAMFUNCTION_H
