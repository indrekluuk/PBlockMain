//
// Created by indrek on 25.03.2017.
//

#include "PBlocksMainModule.h"



void PBlocksMainModule::init() {
  display.init();

  program.getFunction(0)->getNode(0)->setModule(0);
  program.getFunction(0)->getNode(1)->setModule(0);
  program.getFunction(0)->getNode(2)->setModule(0);
  program.getFunction(0)->activateLast();

  program.getFunction(2)->getNode(0)->setModule(0);

  for (uint8_t i = 0; i<18; i++) {
    program.getFunction(3)->getNode(i)->setModule(0);
  }

  for (uint8_t i = 0; i<14; i++) {
    program.getFunction(4)->getNode(i)->setModule(1);
  }

  display.draw(true);
}




void PBlocksMainModule::start() {
  display.touchHandler.check();
  display.updateCursor();
}
