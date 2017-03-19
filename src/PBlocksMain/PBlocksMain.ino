

#include "Screen.h"


Screen screen;

void setup(void) {
  Serial.begin(9600);
  screen.init();

  screen.draw();
}

void loop(void) {

}
