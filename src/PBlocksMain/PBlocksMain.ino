


#include <MCUFRIEND_kbv.h>
//#include <TouchScreen.h>
#include <PBlocksDisplay.h>


PBlocksDisplay display;




void setup(void) {
  Serial.begin(9600);
  display.init();
  display.draw(true);
}



int i = 0;

void loop(void) {

  display.setActiveTab(i);
  display.draw(false);
  if (++i >= 6) i=0;

  delay(1000);
}


