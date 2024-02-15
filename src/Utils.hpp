#ifndef UTILS_HPP
#define UTILS_HPP

#include <raylib.h>

bool MouseHovered(Rectangle constraints);

Rectangle MaintainRatio(Rectangle constraints, Vector2 oldWinSize, Vector2 newWinSize);

#endif // UTILS_HPP
