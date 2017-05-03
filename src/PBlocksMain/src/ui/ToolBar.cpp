//
// Created by indrek on 13.04.2017.
//

#include "ToolBar.h"
#include "PBlocksUserInterface.h"



ToolBar::ToolBar() {
  activeButtonIndex = NONE;
  pressedButtonIndex = NONE;
  drawnAsPressedIndex = NONE;
  resrv = 0;
}


void ToolBar::init() {
  button[0].init(0, &playIcon);
  button[1].init(1, &playNextIcon);
  button[2].init(2, &stopIcon);
  button[3].init(3, &timerIcon);
  button[4].init(4, "E");
  button[5].init(5, "F");
}


bool ToolBar::tap(uint16_t x, uint16_t y, bool hold) {
  uint8_t buttonIndex = getTappedButtonIndex(x, y);
  if (hold) {
    if (activeButtonIndex == NONE) {
      if (buttonIndex != NONE) {
        activeButtonIndex = buttonIndex;
      }
    }
    pressedButtonIndex = activeButtonIndex == buttonIndex ? buttonIndex : NONE;
  } else {
    activeButtonIndex = NONE;
    pressedButtonIndex = NONE;
  }
  draw(false);

  return buttonIndex != NONE;
}

uint8_t ToolBar::getTappedButtonIndex(uint16_t x, uint16_t y) {
  if (y > TOP) {
    for (uint8_t i = 0; i<BUTTON_COUNT; i++) {
      if (x < (i+1)*ToolBarButton::WIDTH) {
        return i;
      }
    }
  }
  return NONE;
}



void ToolBar::draw(bool redrawAll) {
  if (redrawAll) {
    for (int8_t i=0; i<BUTTON_COUNT; i++) {
      button[i].draw(pressedButtonIndex == i);
    }
  } else {
    if (pressedButtonIndex != drawnAsPressedIndex) {
      if (drawnAsPressedIndex != NONE) {
        button[drawnAsPressedIndex].draw(false);
      }
      if (pressedButtonIndex != NONE) {
        button[pressedButtonIndex].draw(true);
      }
      drawnAsPressedIndex = pressedButtonIndex;
    }
  }
}




