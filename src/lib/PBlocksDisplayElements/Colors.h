//
// Created by indrek on 21.03.2017.
//

#ifndef PBLOCKMAIN_COLORS_H_H
#define PBLOCKMAIN_COLORS_H_H



#define COLOR_BLACK   0x0000
#define COLOR_BLUE    0x001F
#define COLOR_RED     0xF800
#define COLOR_GREEN   0x0600
#define COLOR_CYAN    0x07FF
#define COLOR_MAGENTA 0xF81F
#define COLOR_YELLOW  0xFFE0
#define COLOR_WHITE   0xFFFF

#define COLOR_GRAY    0x94B2



#define COLOR_SHEET_INACTIVE    0x52AA
#define COLOR_SHEET_BACKGROUND  0x7BEF
#define COLOR_SHEET_BORDER      WHITE

#define COLOR_PLAY_BUTTON       0X0300






enum Palette {
    BLACK = 0,
    WHITE = 1,
    BLUE = 2,
    GREEN = 3,
    PLAY_BUTTON = 4,
    SHEET_BACKGROUND = 5,
    SHEET_INACTIVE = 6,
    YELLOW = 7,

    TEST = 10,
};





struct RgbColor {

    RgbColor(uint16_t c) {colorCode = c;}

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
        case Palette::GREEN:
          colorCode = COLOR_GREEN;
          break;
        case Palette::YELLOW:
          colorCode = COLOR_YELLOW;
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
        case Palette::TEST:
          colorCode = COLOR_GRAY;
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






struct IconColor {

    union {
        uint16_t rawData;
        struct {
            uint8_t fgColor : 4;
            uint8_t bgColor : 4;
            uint8_t bColor : 4;
            uint8_t hasBorder : 1;
            uint8_t hasBorder3d : 1;
            uint8_t reserved : 2;
        };
    };

    constexpr IconColor(uint16_t rawData) :
        rawData(rawData)
    {}

    constexpr IconColor(
        Palette fgColor,
        Palette bgColor,
        Palette bColor,
        bool hasBorder,
        bool hasBorder3d
    ) :
        fgColor(fgColor),
        bgColor(bgColor),
        bColor(bColor),
        hasBorder(hasBorder),
        hasBorder3d(hasBorder3d),
        reserved(0)
    {}

    constexpr IconColor() :
        fgColor(Palette::WHITE),
        bgColor(Palette::BLACK),
        bColor(Palette::BLACK),
        hasBorder(false),
        hasBorder3d(false),
        reserved(0)
    {}

    void setForegroundColor(Palette p) {fgColor = p;};
    void setBackgroundColor(Palette p) {bgColor = p;};
    void setBorderColor(Palette p) {bColor = p; hasBorder = true; hasBorder3d = false; };
    void setBorder3d() {hasBorder = true; hasBorder3d = true; };
    void setNoBorder() {hasBorder = false;}

    RgbColor getForegroundColor() { return RgbColor((Palette)fgColor); }
    RgbColor getBackgroundColor() { return RgbColor((Palette)bgColor); }
    RgbColor getBorderColor() { return RgbColor((Palette)bColor); }
};





#endif //PBLOCKMAIN_COLORS_H_H
