#ifndef BUTTON_HPP
#define BUTTON_HPP

#include <raylib.h>
#include <functional>
#include <string>

#include "ButtonConfig.hpp"

class Button
{
private:
    Rectangle constraints;
    std::function<void(void)> onClick;
    ButtonConfig buttonConfig;
    std::string text;

public:
    Button(Rectangle constraints, std::string text, std::function<void(void)> onClick, ButtonConfig buttonConfig);
    ~Button();

    void Update();
    void Resize(Vector2 oldWinSize, Vector2 newWinSize);
    void Resize(std::function<Rectangle(void)> resizeFunc);
    void Draw();
};

#endif // BUTTON_HPP