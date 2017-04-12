//
// Created by indrek on 10.04.2017.
//

#include "Sheets.h"
#include "PageGridFunction.h"
#include "PageGridModules.h"
#include "PBlocksUserInterface.h"




Sheets::Sheets() {

}


void Sheets::init(uint16_t screenW, uint16_t screenH) {
  index = 0;
  drawnIndex = SHEET_COUNT;

  tab[0].init(0, &playIcon);
  tab[1].init(1, "f1");
  tab[2].init(2, "f2");
  tab[3].init(3, "f3");
  tab[4].init(4, "f4");
  tab[5].init(5, &modulesIcon);

  PageGrid::staticInit(screenW);
}




void Sheets::tap(uint16_t x, uint16_t y) {

  if (y < Tab::HEIGHT) {
    for (uint8_t i=0; i<SHEET_COUNT; i++) {
      if (x < tab[i].getTabX2()) {
        index = i;
        break;
      }
    }
    if (index != drawnIndex) {
      draw(false);
    }

  } else if (y < Tab::HEIGHT + PageGrid::SHEET_HEIGHT) {
    ProgramFunction * function = Program->getFunction(index);
    if (function != nullptr) {
      PageGridFunction page(*function);
      page.tap(x, y);
    }
  }


}






void Sheets::draw(bool redrawAll) {
  uint32_t m = millis();

  drawTabs(redrawAll);
  drawSheet(redrawAll);

  // render time
  if (index != drawnIndex) {
    UI->tft.setTextSize(1);
    UI->tft.setTextColor(COLOR_WHITE, COLOR_BLACK);
    UI->tft.setCursor(10, 310);
    UI->tft.print((uint16_t)(millis() - m));
    UI->tft.print("  ");
  }

  drawnIndex = index;
}


void Sheets::drawTabs(bool redrawAll) {
  if (redrawAll) {
    for (uint8_t i=0; i<SHEET_COUNT; i++) {
      tab[i].draw(i==index);
    }
  } else if (drawnIndex != index) {
    tab[drawnIndex].draw(false);
    tab[index].draw(true);
  }
}


void Sheets::drawSheet(bool redrawAll) {
  ProgramFunction * function = Program->getFunction(index);
  if (function != nullptr) {
    PageGridFunction page(*function);
    page.draw(redrawAll);
  } else {
    PageGridModules page;
    page.draw(redrawAll);
  }
}


void Sheets::updateCursor() {
  ProgramFunction * function = Program->getFunction(index);
  if (function != nullptr) {
    PageGridFunction page(*function);
    page.updateCursor();
  }
}



