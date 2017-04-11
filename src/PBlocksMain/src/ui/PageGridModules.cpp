//
// Created by indrek on 11.04.2017.
//

#include "PageGridModules.h"
#include "PBlocksUserInterface.h"




void PageGridModules::draw(bool redrawAll) {
  if (redrawAll) {
    clearPage();
  }

  for (uint8_t row=0; row<SLOT_ROW_COUNT; row++) {
    for (uint8_t col=0; col<SLOT_COL_COUNT; col++) {
      drawEmptySlot(col, row, COLOR_GRAY50);
    }
  }
}


