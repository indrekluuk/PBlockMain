//
// Created by indrek on 13.04.2017.
//

#include "ToolBarButton.h"
#include "PBlocksUserInterface.h"



void ToolBarButton::init(uint8_t buttonIndex) {
  index = buttonIndex;
}



void ToolBarButton::draw(bool isPressed) {
  TFT &tft = UI->tft;

  tft.drawFastHLine(index*WIDTH, TOP, WIDTH, isPressed ? COLOR_GRAY33 : COLOR_WHITE);
  tft.drawFastVLine(index*WIDTH, TOP, HEIGHT, isPressed ? COLOR_GRAY33 : COLOR_WHITE);
  tft.drawFastHLine(index*WIDTH, TOP + WIDTH - 1, WIDTH, isPressed ? COLOR_WHITE : COLOR_GRAY33);
  tft.drawFastVLine(index*WIDTH + WIDTH - 1, TOP, HEIGHT, isPressed ? COLOR_WHITE : COLOR_GRAY33);

  tft.fillRect(
      index*WIDTH+1,
      TOP+1,
      WIDTH-2,
      HEIGHT-2,
      isPressed ? COLOR_GRAY66 : COLOR_GRAY85);
}


