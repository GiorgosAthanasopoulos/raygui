#include <iostream>

#include "Button.hpp"
#include "Utils.hpp"

Button::Button()
{
    text = "Click me!";
    onClick = []() {
        std::cout << "Hello, World!\n";
	};
    buttonConfig = {WHITE, GetFontDefault(), 30, 0, BLACK};
    Vector2 textDim = MeasureTextEx(buttonConfig.font, text.c_str(), buttonConfig.fontSize, buttonConfig.fontSpacing);
    this->constraints = { 0, 0, textDim.x + 50, textDim.y + 10 };
}

Button::Button(Rectangle constraints, std::string text, std::function<void(void)> onClick, ButtonConfig buttonConfig)
{
    this->constraints = constraints;
    this->text = text;
    this->onClick = onClick;
    this->buttonConfig = buttonConfig;
}

Button::~Button()
{
}

void Button::Update()
{
    if (MouseHovered(constraints))
    {
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            onClick();
        }
    }
}

void Button::Resize(Vector2 oldWinSize, Vector2 newWinSize)
{
    constraints = MaintainRatio(constraints, oldWinSize, newWinSize);
}

void Button::Resize(std::function<Rectangle(void)> resizeFunc)
{
    constraints = resizeFunc();
}

void Button::Draw()
{
    DrawRectangleRec(constraints, buttonConfig.buttonColor);
    DrawText(text.c_str(),
        constraints.x + constraints.width / 2 -
            MeasureTextEx(buttonConfig.font, text.c_str(), buttonConfig.fontSize, buttonConfig.fontSpacing).x / 2,
        constraints.y + constraints.height / 2 - buttonConfig.fontSize / 2,
        buttonConfig.fontSize, buttonConfig.textColor);
}
