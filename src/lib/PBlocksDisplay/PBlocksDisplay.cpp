//
// Created by indrek on 25.03.2017.
//


#include "PBlocksDisplay.h"
#include "Colors.h"
#include <MCUFRIEND_kbv.h>
#include <TouchScreen.h>


#define YP A1   //[A1], A3 for ILI9320, A2 for ST7789V
#define YM 7    //[ 7], 9             , 7
#define XM A2   //[A2], A2 for ILI9320, A1 for ST7789V
#define XP 6    //[ 6], 8             , 6

TouchScreen myTouch(XP, YP, XM, YM, 300);
MCUFRIEND_kbv tft;



void PBlocksDisplay::init() {
  tft.begin(0x9488);
  tft.setRotation(1);
  tft.fillScreen(BLACK);

  for (uint8_t i=0; i<SHEET_COUNT; i++) {
    sheets[i].init(TAB_WIDTH*i, TAB_WIDTH);
  }
  A1;
  sheets[2].setSelected(true);

}


void PBlocksDisplay::setActiveTab(uint16_t tabIndex) {
  for (uint8_t i=0; i<SHEET_COUNT; i++) {
    sheets[i].setSelected(tabIndex == i);
  }
}


void PBlocksDisplay::draw(bool redrawAll) {
  updateSheets(redrawAll);

}

void PBlocksDisplay::updateSheets(bool redrawAll) {
  Sheet * selectedSheet = nullptr;
  for (uint8_t i=0; i<SHEET_COUNT; i++) {
    if (sheets[i].isSelected()) {
      selectedSheet = &sheets[i];
    } else {
      sheets[i].draw(redrawAll);
    }
  }
  if (selectedSheet) {
    selectedSheet->draw(redrawAll);
  }
}



