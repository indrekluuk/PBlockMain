//
// Created by indrek on 21.03.2017.
//

#ifndef PBLOCKMAIN_COLORS_H_H
#define PBLOCKMAIN_COLORS_H_H



#define COLOR_WHITE       0xFFFF
#define COLOR_GRAY85      0xDEDB
#define COLOR_GRAY66      0xAD55
#define COLOR_GRAY50      0x7BEF
#define COLOR_GRAY33      0x52AA
#define COLOR_BLACK       0x0000

#define COLOR_BLUE        0x001F
#define COLOR_RED         0xF800
#define COLOR_GREEN       0x0600
#define COLOR_DARK_GREEN  0X0300
#define COLOR_CYAN        0x07FF
#define COLOR_MAGENTA     0xF81F
#define COLOR_YELLOW      0xFFE0





enum Palette {
    BLACK = 0,
    WHITE = 1,
    GRAY85 = 2,
    GRAY66 = 3,
    GRAY50 = 4,
    GRAY33 = 5,
    BLUE = 6,
    GREEN = 7,
    DARK_GREEN = 8,
    YELLOW = 9,
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
        case Palette::GRAY85:
          colorCode = COLOR_GRAY85;
          break;
        case Palette::GRAY66:
          colorCode = COLOR_GRAY66;
          break;
        case Palette::GRAY50:
          colorCode = COLOR_GRAY50;
          break;
        case Palette::GRAY33:
          colorCode = COLOR_GRAY33;
          break;
        case Palette::BLUE:
          colorCode = COLOR_BLUE;
          break;
        case Palette::GREEN:
          colorCode = COLOR_GREEN;
          break;
        case Palette::DARK_GREEN:
          colorCode = COLOR_DARK_GREEN;
          break;
        case Palette::YELLOW:
          colorCode = COLOR_YELLOW;
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
