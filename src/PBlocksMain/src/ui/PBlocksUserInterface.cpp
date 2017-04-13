//
// Created by indrek on 25.03.2017.
//


#include "PBlocksUserInterface.h"



PBlocksUserInterface * UI;



PBlocksUserInterface::PBlocksUserInterface() {
  UI = this;
}


void PBlocksUserInterface::init() {
  tft.begin(0x9488);
  tft.setRotation(1);
  tft.fillScreen(COLOR_BLACK);

  sheets.init();
  toolBar.init();
  touchHandler.init((uint16_t)tft.width(), (uint16_t)tft.height());
}



void PBlocksUserInterface::draw(bool redrawAll) {
  sheets.draw(redrawAll);
  toolBar.draw(redrawAll);
}



void PBlocksUserInterface::run() {
  touchHandler.check();
  sheets.updateCursor();
}


