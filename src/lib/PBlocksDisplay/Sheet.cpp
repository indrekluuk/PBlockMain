//
// Created by indrek on 25.03.2017.
//

#include "Sheet.h"
#include "Colors.h"
#include "PBlocksDisplay.h"



Sheet::Sheet() :
    tabIndex(0xF),
    selected(false),
    isDrawnAsSelected(false)
{
}


void Sheet::init(uint8_t index, IconBuffer * icon, const char * label) {
  tabIndex = index;
  tabIcon = icon;
  tabLabel = label;
}

void Sheet::tap(uint16_t x, uint16_t y) {
  uint16_t tabX = getTabX();
  if (isTapIn(x, tabX, TAB_WIDTH) && isTapIn(y, 0, TAB_HEIGHT)) {
    Display->setActiveTab(tabIndex);
  }
}



void Sheet::setSelected(bool isSelected) {
  selected = isSelected;
}

bool Sheet::isSelected() {
  return selected;
}



void Sheet::draw(bool redrawAll) {
  drawTab(redrawAll);
  drawSheet(redrawAll);
  isDrawnAsSelected = selected;
}

void Sheet::drawTab(bool redrawAll) {
  if (redrawAll || isDrawnAsSelected != selected) {
    TFT & tft = Display->tft;
    uint16_t tabX = getTabX();

    if (tabIcon != nullptr) {
      if (selected) {
        tft.drawIcon(tabX + 1, 0, *tabIcon, TAB_WIDTH - 2, TAB_HEIGHT, 2);
      } else {
        IconColor tmp = tabIcon->color;
        tabIcon->color.setDrawColor(Palette::BLACK);
        tabIcon->color.setBackgroundColor(Palette::SHEET_INACTIVE);
        tft.drawIcon(tabX + 1, 0, *tabIcon, TAB_WIDTH - 2, TAB_HEIGHT, 2);
        tabIcon->color = tmp;
      }

      tft.drawFastHLine(tabX + 1 , TAB_HEIGHT , TAB_WIDTH - 2, selected ? COLOR_SHEET_BACKGROUND : COLOR_BLACK);
    } else {
      tft.fillRect(tabX + 1, 0, TAB_WIDTH - 2, TAB_HEIGHT, selected ? COLOR_SHEET_BACKGROUND : COLOR_SHEET_INACTIVE);
      tft.drawFastHLine(tabX + 1 , TAB_HEIGHT , TAB_WIDTH - 2, selected ? COLOR_SHEET_BACKGROUND : COLOR_BLACK);

      if (tabLabel != nullptr) {
        tft.setCursor(tabX + 10, TAB_HEIGHT / 2 - 7);
        tft.setTextColor(selected ? COLOR_WHITE : COLOR_BLACK);
        tft.setTextSize(2);
        tft.print(tabLabel);
      }
    }
  }
}


void Sheet::drawSheet(bool redrawAll) {
  if (selected && (redrawAll || isDrawnAsSelected != selected)) {
    TFT & tft = Display->tft;
    uint16_t tabX = getTabX();
    if (redrawAll) {
      tft.fillRect(0, TAB_HEIGHT + 1, tft.width(), SHEET_HEIGHT, COLOR_SHEET_BACKGROUND);
    }
    tft.fillRect(10, TAB_HEIGHT + 10, 50, 7, COLOR_SHEET_BACKGROUND);

    tft.setCursor(10, TAB_HEIGHT + 10);
    tft.setTextColor(COLOR_WHITE);
    tft.setTextSize(1);
    tft.print(tabX);
  }
}


uint16_t Sheet::getTabX() {
  return tabIndex*TAB_WIDTH;
}


