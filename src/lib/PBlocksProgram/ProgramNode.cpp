//
// Created by indrek on 1.04.2017.
//

#include "ProgramNode.h"
#include "PBlocksProgram.h"



ProgramNode::ProgramNode() {
  module = PBlocksProgram::MODULE_NONE;
  reserved = 0;
}



bool ProgramNode::isEmpty() {
  return module == PBlocksProgram::MODULE_NONE;
}

Module* ProgramNode::getModule() {
  if (isEmpty()) {
    return nullptr;
  } else {
    return &(Program->modules[module]);
  }
}


void ProgramNode::setModule(uint8_t moduleIndex) {
  module = moduleIndex;
}


