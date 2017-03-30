//
// Created by indrek on 25.03.2017.
//

#include "PBlocksMainModule.h"



void PBlocksMainModule::init() {
  display.init();
  display.draw(true);
/*
  display.tft.drawRect(49, 79, 62, 62, COLOR_YELLOW);


  IconBuffer iconBuffer;
  uint8_t i=0;
  iconBuffer.setBitmap(i++, 0b0000111110000000);
  iconBuffer.setBitmap(i++, 0b0001100001100000);
  iconBuffer.setBitmap(i++, 0b0110010010110000);
  iconBuffer.setBitmap(i++, 0b1100000000011000);
  iconBuffer.setBitmap(i++, 0b0110011110001000);
  iconBuffer.setBitmap(i++, 0b0011100001110000);
  iconBuffer.setBitmap(i++, 0b0000111110000000);
  iconBuffer.setBitmap(i++, 0b0000001100000000);
  iconBuffer.setBitmap(i++, 0b1111111111111111);
  iconBuffer.setBitmap(i++, 0b0000001100000000);
  iconBuffer.setBitmap(i++, 0b0000001100000000);
  iconBuffer.setBitmap(i++, 0b0000001100000000);
  iconBuffer.setBitmap(i++, 0b0000011011000000);
  iconBuffer.setBitmap(i++, 0b0001100001100000);
  iconBuffer.setBitmap(i++, 0b0011000000110000);
  iconBuffer.setBitmap(i  , 0b0111000000111000);

  iconBuffer.color.setDrawColor(Palette::BLUE);
  iconBuffer.color.setBackgroundColor(Palette::SHEET_BACKGROUND);

  display.tft.drawIcon(50, 80, iconBuffer, 60, 60, 1);
  display.tft.drawIcon(150, 80, iconBuffer, 60, 60, 2);
  display.tft.drawIcon(250, 80, iconBuffer, 60, 60, 3);
  display.tft.drawIcon(50, 160, iconBuffer, 60, 60, 1);
  display.tft.drawIcon(150, 160, iconBuffer, 60, 60, 2);
  display.tft.drawIcon(250, 160, iconBuffer, 60, 60, 3);

  iconBuffer.color.setBorderColor(Palette::WHITE);
  iconBuffer.color.setDrawColor(Palette::GREEN);
  iconBuffer.color.setBorder3d();
  display.tft.drawIcon(350, 80, iconBuffer, 120, 120, 6);
*/

}




void PBlocksMainModule::start() {
  display.touchHandler.check();
}
