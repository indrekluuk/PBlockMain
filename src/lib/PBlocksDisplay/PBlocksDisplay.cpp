//
// Created by indrek on 25.03.2017.
//


#include "PBlocksDisplay.h"
#include "Colors.h"



PBlocksDisplay * Display;




void PBlocksDisplay::init() {
  tft.begin(0x9488);
  tft.setRotation(1);
  tft.fillScreen(COLOR_BLACK);


  uint8_t i=0;
  playIcon.setBitmap(i++, 0b1100000000000000);
  playIcon.setBitmap(i++, 0b1111000000000000);
  playIcon.setBitmap(i++, 0b1111110000000000);
  playIcon.setBitmap(i++, 0b1111111100000000);
  playIcon.setBitmap(i++, 0b1111111111000000);
  playIcon.setBitmap(i++, 0b1111111111110000);
  playIcon.setBitmap(i++, 0b1111111111111100);
  playIcon.setBitmap(i++, 0b1111111111111111);
  playIcon.setBitmap(i++, 0b1111111111111111);
  playIcon.setBitmap(i++, 0b1111111111111100);
  playIcon.setBitmap(i++, 0b1111111111110000);
  playIcon.setBitmap(i++, 0b1111111111000000);
  playIcon.setBitmap(i++, 0b1111111100000000);
  playIcon.setBitmap(i++, 0b1111110000000000);
  playIcon.setBitmap(i++, 0b1111000000000000);
  playIcon.setBitmap(i++, 0b1100000000000000);
  playIcon.color = COLOR_PLAY_BUTTON;
  playIcon.hasBorder = true;

  playIcon2 = playIcon;
  playIcon2.hasBorder = false;

  i=0;
  modulesIcon.setBitmap(i++, 0b0000001111000000);
  modulesIcon.setBitmap(i++, 0b0000001111000000);
  modulesIcon.setBitmap(i++, 0b0000001111000000);
  modulesIcon.setBitmap(i++, 0b0000001111000000);
  modulesIcon.setBitmap(i++, 0b0000000100000000);
  modulesIcon.setBitmap(i++, 0b0000000100000000);
  modulesIcon.setBitmap(i++, 0b0000000100000000);
  modulesIcon.setBitmap(i++, 0b0111111111111110);
  modulesIcon.setBitmap(i++, 0b0100000010000010);
  modulesIcon.setBitmap(i++, 0b0100000010000010);
  modulesIcon.setBitmap(i++, 0b0100000010000010);
  modulesIcon.setBitmap(i++, 0b0100000010000010);
  modulesIcon.setBitmap(i++, 0b1111001111001111);
  modulesIcon.setBitmap(i++, 0b1111001111001111);
  modulesIcon.setBitmap(i++, 0b1111001111001111);
  modulesIcon.setBitmap(i++, 0b1111001111001111);
  modulesIcon.color = COLOR_WHITE;


  sheets[0].init(0, &playIcon, nullptr);
  sheets[1].init(1, &playIcon2, "f1");
  sheets[2].init(2, nullptr, "f2");
  sheets[3].init(3, nullptr, "f3");
  sheets[4].init(4, nullptr, "f4");
  sheets[5].init(5, &modulesIcon, nullptr);

  sheets[0].setSelected(true);

  Display = this;
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



