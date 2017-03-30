//
// Created by indrek on 25.03.2017.
//

#include "ProgramSlot.h"
#include "PBlocksDisplay.h"





void ProgramSlot::init(uint16_t x, uint16_t y) {
  this->x = x;
  this->y = y;
}



void ProgramSlot::draw() {
  bool empty = true;
  TFT & tft = Display->tft;

  if (empty) {
    //tft.fillRect(x, y, WIDTH, HEIGHT, COLOR_BLACK);
    tft.drawRect(x, y, WIDTH, HEIGHT, COLOR_BLACK);
    /*
    tft.drawFastHLine(x, y, WIDTH, COLOR_BLACK);
    tft.drawFastVLine(x, y, HEIGHT, COLOR_BLACK);
    tft.drawFastHLine(x, y + HEIGHT, WIDTH, COLOR_WHITE);
    tft.drawFastVLine(x + WIDTH, y, HEIGHT, COLOR_WHITE);
     */
  } else {
    tft.setTextSize(1);
    tft.setTextColor(COLOR_WHITE);
    tft.drawRect(x, y, WIDTH, HEIGHT, COLOR_YELLOW);
    tft.drawRect(x + 6, y + 4, 32, 32, COLOR_YELLOW);
    tft.setCursor(x + 42, y + 18);
    tft.print("M01");
    tft.setCursor(x + 6, y + 46);
    tft.print("1 sek");
  }
}




