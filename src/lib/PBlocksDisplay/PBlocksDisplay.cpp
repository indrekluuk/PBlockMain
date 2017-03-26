//
// Created by indrek on 25.03.2017.
//


#include "PBlocksDisplay.h"
#include "Colors.h"


MCUFRIEND_kbv PBlocksDisplay::tft;
TouchHandler PBlocksDisplay::touchHandler;



void PBlocksDisplay::init() {
  tft.begin(0x9488);
  tft.setRotation(1);
  tft.fillScreen(BLACK);

  for (uint8_t i=0; i<SHEET_COUNT; i++) {
    sheets[i].init(this, i, TAB_WIDTH*i, TAB_WIDTH);
  }
  sheets[0].setSelected(true);
}


void PBlocksDisplay::setActiveTab(uint16_t tabIndex) {
  for (uint8_t i=0; i<SHEET_COUNT; i++) {
    sheets[i].setSelected(tabIndex == i);
  }
  draw(false);
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



