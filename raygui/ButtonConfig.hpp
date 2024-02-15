#ifndef BUTTONCONFIG_HPP_
#define BUTTONCONFIG_HPP_

#include <raylib.h>

typedef struct ButtonConfig
{
    Color buttonColor;

    Font font;
    int fontSize;
    int fontSpacing;
    Color textColor;
} ButtonConfig;

#endif // BUTTONCONFIG_HPP_