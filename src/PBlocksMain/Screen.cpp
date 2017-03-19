//
// Created by indrek on 19.03.2017.
//

#include "Screen.h"



Screen::Screen() {

}


void Screen::init() {
  tft.begin(0x9488);
}


void Screen::draw() {
  tft.setRotation(0);
  tft.fillScreen(BLUE);
}


