//
// Created by indrek on 21.03.2017.
//

#ifndef PBLOCKMAIN_COLORS_H_H
#define PBLOCKMAIN_COLORS_H_H



#define COLOR_BLACK   0x0000
#define COLOR_BLUE    0x001F
#define COLOR_RED     0xF800
#define COLOR_GREEN   0x07E0
#define COLOR_CYAN    0x07FF
#define COLOR_MAGENTA 0xF81F
#define COLOR_YELLOW  0xFFE0
#define COLOR_WHITE   0xFFFF


#define COLOR_SHEET_INACTIVE    0x52AA
#define COLOR_SHEET_BACKGROUND  0x7BEF
#define COLOR_SHEET_BORDER      WHITE

#define COLOR_PLAY_BUTTON       0X0300




enum Palette
{
    BLACK = 0,
    WHITE = 1,
    BLUE = 2,
    PLAY_BUTTON = 3,
    SHEET_BACKGROUND = 4,
    SHEET_INACTIVE = 5,
};



struct RgbColor {

    RgbColor(Palette p) {
      switch (p) {
        default:
        case Palette::BLACK:
          colorCode = COLOR_BLACK;
          break;
        case Palette::WHITE:
          colorCode = COLOR_WHITE;
          break;
        case Palette::BLUE:
          colorCode = COLOR_BLUE;
          break;
        case Palette::PLAY_BUTTON:
          colorCode = COLOR_PLAY_BUTTON;
          break;
        case Palette::SHEET_BACKGROUND:
          colorCode = COLOR_SHEET_BACKGROUND;
          break;
        case Palette::SHEET_INACTIVE:
          colorCode = COLOR_SHEET_INACTIVE;
          break;
      }
    }

    union {
        uint16_t colorCode;
        struct {
            uint8_t colorL;
            uint8_t colorH;
        };
    };
};




#endif //PBLOCKMAIN_COLORS_H_H
