//
// Created by indrek on 1.04.2017.
//

#include "ProgramFunction.h"




ProgramFunction::ProgramFunction() {
  setActiveNode(NODE_COUNT);
}




ProgramNode * ProgramFunction::getNode(uint8_t index) {
  return index < NODE_COUNT ? &nodes[index] : nullptr;
}

void ProgramFunction::setActiveNode(uint8_t index) {
  if (index >= NODE_COUNT || nodes[index].isEmpty()) {
    for (uint8_t i=0; i<NODE_COUNT; i++) {
      if (nodes[i].isEmpty()) {
        activeNodeIndex = i;
        return;
      }
    }
    activeNodeIndex = NODE_COUNT;
  } else {
    activeNodeIndex = index;
  }
}

void ProgramFunction::activateLast() {
  setActiveNode(NODE_COUNT);
}


uint8_t ProgramFunction::getActiveNodeIndex() {
  return activeNodeIndex;
}


ProgramNode * ProgramFunction::getActiveNode() {
  return activeNodeIndex < NODE_COUNT ? &nodes[activeNodeIndex] : nullptr;
}


