


#include <MCUFRIEND_kbv.h>
#include <TouchScreen.h>
#include <PBlocksDisplay.h>
#include "PBlocksMainModule.h"




PBlocksMainModule module;




void setup(void) {
  Serial.begin(9600);
  module.init();

}



void loop(void) {
  module.start();
}


