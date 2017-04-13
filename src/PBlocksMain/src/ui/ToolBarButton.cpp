//
// Created by indrek on 13.04.2017.
//

#include "ToolBarButton.h"
#include "PBlocksUserInterface.h"



void ToolBarButton::init(uint8_t buttonIndex) {
  index = buttonIndex;
}



void ToolBarButton::draw() {
  TFT &tft = UI->tft;

  tft.drawFastHLine(index*WIDTH, TOP, WIDTH, COLOR_GRAY85);
  tft.drawFastVLine(index*WIDTH, TOP, HEIGHT, COLOR_GRAY85);
  tft.drawFastHLine(index*WIDTH, TOP + WIDTH - 1, WIDTH, COLOR_GRAY33);
  tft.drawFastVLine(index*WIDTH + WIDTH - 1, TOP, HEIGHT, COLOR_GRAY33);

  tft.fillRect(
      index*WIDTH+1,
      TOP+1,
      WIDTH-2,
      HEIGHT-2,
      COLOR_GRAY50);
}


