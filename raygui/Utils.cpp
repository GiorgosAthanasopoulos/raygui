#include "Utils.hpp"

bool MouseHovered(Rectangle constraints)
{
    return (GetMouseX() >= constraints.x && GetMouseX() <= constraints.x + constraints.width && GetMouseY() >= constraints.y && GetMouseY() <= constraints.y + constraints.height);
}

Rectangle MaintainRatio(Rectangle constraints, Vector2 oldWinSize, Vector2 newWinSize)
{
    return {
        (constraints.x / oldWinSize.x) * newWinSize.x,
        (constraints.y / oldWinSize.y) * newWinSize.y,
        constraints.width, // (constraints.width / oldWinSize.x) * newWinSize.x,
        constraints.height // (constraints.height / oldWinSize.y) * newWinSize.y};
    };
}
