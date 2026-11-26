#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>


class Button{
    private:
    enum Origins{
        TopLeft,
        TopRight,
        LowerLeft,
        LowerRight,
        Center
    };
    sf::RectangleShape shape;
    sf::Font font;
    sf::Text text;
    void initFont();
    void initButton(sf::Vector2f size);
    void centerButton();
    public:
    void setFont(sf::Font &font);
    bool mouseCollision(sf::RenderWindow *window);
    void setButtonColour(sf::Color colour);
    void setString(std::string string);
    void setTextScale(float scale);
    void render(sf::RenderTarget *target);
    void setPosition(sf::Vector2f pos);
    Button(sf::Vector2f size);
};