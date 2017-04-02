//
// Created by indrek on 25.03.2017.
//

#include "PBlocksMainModule.h"



void PBlocksMainModule::init() {
  display.init();

  program.functions[0].nodes[0].setModule(0);
  program.functions[0].nodes[1].setModule(0);
  program.functions[0].nodes[3].setModule(0);
  program.functions[2].nodes[0].setModule(0);

  for (uint8_t i = 0; i<18; i++) {
    program.functions[3].nodes[i].setModule(0);
  }

  for (uint8_t i = 0; i<14; i++) {
    program.functions[4].nodes[i].setModule(1);
  }

  display.draw(true);
}




void PBlocksMainModule::start() {
  display.touchHandler.check();
}
