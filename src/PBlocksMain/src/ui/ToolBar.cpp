//
// Created by indrek on 13.04.2017.
//

#include "ToolBar.h"
#include "PBlocksUserInterface.h"


void ToolBar::init() {
  button[0].init(0);
  button[1].init(1);
  button[2].init(2);
  button[3].init(3);
  button[4].init(4);
  button[5].init(5);
}


void ToolBar::tap(uint16_t x, uint16_t y, bool hold) {
  if (TOP > y) {
    for (uint8_t i = 0; i<BUTTON_COUNT; i++) {
      if (x < (i+1)*ToolBarButton::WIDTH) {

        return;
      }
    }
  }
}



void ToolBar::draw(bool redrawAll) {
  if (redrawAll) {
    UI->tft.fillRect(0, TOP+1, SCREEN_WIDTH, HEIGHT, COLOR_GRAY33);
  }
/*
  for (uint8_t i=0; i<BUTTON_COUNT; i++) {
    button[i].draw();
  }
*/
}




