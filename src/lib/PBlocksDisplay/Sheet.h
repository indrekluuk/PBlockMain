//
// Created by indrek on 25.03.2017.
//

#ifndef PBLOCKMAIN_SHEET_H
#define PBLOCKMAIN_SHEET_H


#include <stdint.h>


class Sheet {

    static const uint16_t TAB_HEIGHT = 60;
    static const uint16_t SHEET_HEIGHT = 200;

    int16_t tabX = 0;
    int16_t tabW = 0;
    bool selected = false;
    bool isDrawnAsSelected = false;

public:

    void init(int16_t tabX, int16_t tabW);

    void setSelected(bool isSelected);
    bool isSelected();

    void draw(bool redrawAll);
    void drawTab(bool redrawAll);
    void drawSheet(bool redrawAll);

};


#endif //PBLOCKMAIN_SHEET_H
