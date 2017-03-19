//
// Created by indrek on 19.03.2017.
//

#ifndef PBLOCKMAIN_SCREEN_H
#define PBLOCKMAIN_SCREEN_H


#include "Adafruit_GFX.h"
#include <MCUFRIEND_kbv.h>



#define BLACK   0x0000
#define BLUE    0x001F
#define RED     0xF800
#define GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF



class Screen {

public:
    Screen();

    void init();
    void draw();


private:
    MCUFRIEND_kbv tft;

};


#endif //PBLOCKMAIN_SCREEN_H
