//
// Created by indrek on 19.03.2017.
//

#include "Screen.h"



Screen::Screen() {

}


void Screen::init() {
  tft.begin(0x9488);
  tft.setRotation(1);
}


void Screen::draw() {
  tft.fillScreen(BLACK);
  /*
  tft.drawRect(0,0,16,16,YELLOW);
  tft.drawRect(28,4,32,32,YELLOW);
  tft.drawRect(0,0,64,64,YELLOW);
  tft.print("Tere!õüäöÕÜÄÖ");
  tft.setTextSize(10);
  tft.print("Tere!");
*/
  tft.setTextSize(1);


  int esimeneX = 14;
  int esimeneY = 58;
  int vaheX = 78;
  int vaheY = 70;
  int a = 0;

  for (int j=0; j<3; j++) {
    for (int i=0; i<6; i++) {
      nupp(esimeneX + vaheX*i, esimeneY + vaheY*j, a > 10);
      a++;
    }
  }
}


void Screen::nupp(int x , int y, bool tyhi) {
  if (tyhi) {
    tft.drawRect(x, y, 64, 64, GRAY);
  } else {
    tft.drawRect(x, y, 64, 64, YELLOW);
    tft.drawRect(x + 6, y + 4, 32, 32, YELLOW);
    tft.setCursor(x + 42, y + 18);
    tft.print("M01");
    tft.setCursor(x + 6, y + 46);
    tft.print("1 sek");
  }

}


