#ifndef BUTTONCONFIG_HPP_
#define BUTTONCONFIG_HPP_

#include <raylib.h>

typedef struct ButtonConfig
{
    Color buttonColor;

    Font font;
    int fontSize;
    int spacing;
    Color textColor;
} ButtonConfig;

const ButtonConfig DefaultButtonConfig = {
    WHITE,
    GetFontDefault(),
    30,
    0,
    BLACK,
};

#endif // BUTTONCONFIG_HPP_