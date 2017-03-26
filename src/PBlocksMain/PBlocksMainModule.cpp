//
// Created by indrek on 25.03.2017.
//

#include "PBlocksMainModule.h"


#include "Colors.h"


void PBlocksMainModule::init() {
  display.init();
  display.draw(true);

  display.tft.drawRect(49, 79, 62, 62, YELLOW);


  IconBuffer iconBuffer(60, 60, 10, 10, GREEN, SHEET_BACKGROUND);
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
  iconBuffer.setBitmap(i  , 0b0110000000011000);

  iconBuffer.scale = 1;
  display.tft.drawIcon(50, 80, iconBuffer);

  iconBuffer.scale = 2;
  display.tft.drawIcon(150, 80, iconBuffer);

  iconBuffer.scale = 3;
  display.tft.drawIcon(250, 80, iconBuffer);


  iconBuffer.scale = 1;
  display.tft.drawIcon(50, 160, iconBuffer);

  iconBuffer.scale = 2;
  display.tft.drawIcon(150, 160, iconBuffer);

  iconBuffer.scale = 3;
  display.tft.drawIcon(250, 160, iconBuffer);



  iconBuffer.scale = 6;
  iconBuffer.width = 120;
  iconBuffer.height = 120;
  display.tft.drawIcon(350, 80, iconBuffer);


}




void PBlocksMainModule::start() {
  display.touchHandler.check();
}
