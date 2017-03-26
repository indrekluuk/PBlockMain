//
// Created by indrek on 25.03.2017.
//

#include "PBlocksMainModule.h"








void PBlocksMainModule::init() {
  display.init();
  display.draw(true);
}



int i=0;

void PBlocksMainModule::start() {
  display.touchHandler.check();
}
