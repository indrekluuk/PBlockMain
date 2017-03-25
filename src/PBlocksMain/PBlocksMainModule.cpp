//
// Created by indrek on 25.03.2017.
//

#include "PBlocksMainModule.h"
#include <Arduino.h>








void PBlocksMainModule::init() {
  display.init();
  display.draw(true);
}



int i=0;

void PBlocksMainModule::start() {
  display.setActiveTab(i);
  display.draw(false);
  if (++i >= 6) i=0;

  delay(1000);
}
