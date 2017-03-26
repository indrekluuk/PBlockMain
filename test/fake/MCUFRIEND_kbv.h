//
// Created by indrek on 26.03.2017.
//

#ifndef PBLOCKMAIN_MCUFRIEND_KBV_H
#define PBLOCKMAIN_MCUFRIEND_KBV_H


class MCUFRIEND_kbv {

public:

    void begin(int) {}
    void setRotation(int) {}

    int width() { return 0;}
    int height() { return 0;}


    void fillScreen(int) {}
    void fillRect(int, int, int, int, int) {};
    void drawFastHLine(int, int, int, int) {};
    void setCursor(int, int) {};
    void print(int) {};


};


#endif //PBLOCKMAIN_MCUFRIEND_KBV_H
