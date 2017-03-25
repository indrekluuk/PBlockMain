//
// Created by indrek on 25.03.2017.
//

#include "PBlocksMainModule.h"
#include <Arduino.h>


#include <TouchScreen.h>


#define YP A1   //[A1], A3 for ILI9320, A2 for ST7789V
#define YM 7    //[ 7], 9             , 7
#define XM A2   //[A2], A2 for ILI9320, A1 for ST7789V
#define XP 6    //[ 6], 8             , 6

TouchScreen myTouch(XP, YP, XM, YM, 300);
TSPoint tp;

void readResistiveTouch(void)
{
  tp = myTouch.getPoint();
  pinMode(YP, OUTPUT);      //restore shared pins
  pinMode(XM, OUTPUT);
  digitalWrite(YP, HIGH);   //because TFT control pins
  digitalWrite(XM, HIGH);
}





void PBlocksMainModule::init() {
  display.init();
  display.draw(true);
}



int i=0;

bool isPos(int p, int r) {
  return p > r - 65 && p < r + 65;
}

void PBlocksMainModule::start() {


  readResistiveTouch();
  if (tp.z > 100) {
    if (isPos(tp.y, 880)) display.setActiveTab(0);
    if (isPos(tp.y, 740)) display.setActiveTab(1);
    if (isPos(tp.y, 600)) display.setActiveTab(2);
    if (isPos(tp.y, 460)) display.setActiveTab(3);
    if (isPos(tp.y, 320)) display.setActiveTab(4);
    if (isPos(tp.y, 170)) display.setActiveTab(5);
    display.draw(false);
  }
  /*
  Serial.print(tp.x);
  Serial.print(" ");
  Serial.print(tp.y);
  Serial.print(" ");
  Serial.println();
  */
  /*
  while (true) {
    display.setActiveTab(i);
    display.draw(false);
    if (++i >= 6) i=0;

    delay(1000);
  }
   */
}
