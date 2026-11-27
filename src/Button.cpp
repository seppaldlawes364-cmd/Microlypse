#include "../UsableThings/Button.h"

void Button::initFont()
{
    this -> text.setFillColor(sf::Color::Black);
    this -> text.setScale(1,1);
}

void Button::initButton(sf::Vector2f size)
{
    this -> shape.setSize(size);
    this -> shape.setOutlineColor(sf::Color::Black);
    this -> shape.setOutlineThickness(8);
}

void Button::centerButton()
{
    sf::Vector2f sizeShape = this -> shape.getSize();
    sf::Vector2f textBounds = this -> text.getLocalBounds().getSize();
    this->shape.setOrigin(sizeShape.x/2.f,sizeShape.y/2.f);
    this->text.setOrigin(textBounds.x/2.f,textBounds.y/2.f);
    this -> text.setPosition(this -> shape.getPosition());
}

void Button::setFont(sf::Font &font)
{
    this -> text.setFont(font);
}

bool Button::mouseCollision(sf::RenderWindow *window)
{
    
    sf::Vector2i mousePos = sf::Mouse::getPosition(*window);
    sf::Vector2f mouseWindowPos = window->mapPixelToCoords(mousePos);
    
    if(this -> shape.getGlobalBounds().contains(mouseWindowPos)){
        return true;
    }
    return false;
}

void Button::setButtonColour(sf::Color colour)
{
    this -> shape.setFillColor(colour);    
}

void Button::setString(std::string string)
{
    this -> text.setString(string);
    this -> centerButton();
}

void Button::setTextScale(float scale)
{
    this -> text.setCharacterSize(this -> text.getCharacterSize()*scale);
    this -> centerButton();
}

void Button::render(sf::RenderTarget *target)
{
    target->draw(this -> shape);
    target-> draw(this -> text);
}

void Button::setPosition(sf::Vector2f pos)
{
    this -> text.setPosition(pos);
    this -> shape.setPosition(pos);
}

Button::Button(sf::Vector2f size)
{
    this -> initFont();
    this -> initButton(size);
}