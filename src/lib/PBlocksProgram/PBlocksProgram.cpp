//
// Created by indrek on 1.04.2017.
//

#include "PBlocksProgram.h"


PBlocksProgram * Program;




PBlocksProgram::PBlocksProgram() {
  Program = this;
}

ProgramFunction * PBlocksProgram::getFunction(uint8_t index) {
  return index < FUNCTION_COUNT ? &functions[index] : nullptr;
}





