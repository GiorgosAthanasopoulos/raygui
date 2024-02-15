#include "Button.hpp"
#include "Utils.hpp"

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
    DrawText(text.c_str(), constraints.x + constraints.width / 2 - MeasureText(text.c_str(), buttonConfig.fontSize) / 2, constraints.y + constraints.height / 2 - buttonConfig.fontSize / 2, buttonConfig.fontSize, buttonConfig.textColor);
}
