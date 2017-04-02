//
// Created by indrek on 26.03.2017.
//

#ifndef PBLOCKMAIN_MCUFRIEND_KBV_H
#define PBLOCKMAIN_MCUFRIEND_KBV_H


#define CS_ACTIVE ;
#define CD_DATA ;
#define CS_IDLE ;

class MCUFRIEND_kbv {


protected:
    uint16_t
        textcolor, textbgcolor;
    uint8_t
        textsize;
    int16_t
        cursor_x, cursor_y;
    boolean
        _cp437;
public:

    void begin(int) {}
    void setRotation(int) {}
    void setAddrWindow(int, int, int, int) {};
    void WriteCmd(int) {};


    int width() { return 0;}
    int height() { return 0;}


    void fillScreen(int) {}
    void fillRect(int, int, int, int, int) {};
    void drawRect(int, int, int, int, int) {};
    void drawFastHLine(int, int, int, int) {};
    void setCursor(int, int) {};
    void setTextColor(int) {};
    void setTextColor(int, int) {};
    void setTextSize(int) {};
    void print(int) {};
    void print(const char *) {};
    void write8(int) {};

    virtual size_t write(uint8_t) {};

};


extern static const unsigned char font[];


#endif //PBLOCKMAIN_MCUFRIEND_KBV_H
