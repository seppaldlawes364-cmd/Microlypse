#include "../UsableThings/Slider.h"

void Slider::initShapes()
{
    this -> sliderBar.setSize({500,40});
    float barHeight = sliderBar.getSize().y;
    this -> sliderBar.setOrigin(0,barHeight/2);
    this -> sliderBar.setOutlineThickness(7);
    this -> sliderBar.setOutlineColor(sf::Color::Black);
    
    this -> sliderPoint.setRadius(30);
    this -> sliderPoint.setFillColor(sf::Color::Red);
    sf::Vector2f pointSize = sliderPoint.getLocalBounds().getSize();
    this -> sliderPoint.setOrigin(pointSize.x/2,pointSize.y/2);
    this -> sliderPoint.setOutlineThickness(5);
    this -> sliderPoint.setOutlineColor(sf::Color::Black);
}

Slider::Slider()
{
    this -> initShapes();
}

Slider::~Slider()
{
}

float Slider::getPercentage()
{
    float sliderPos = this -> sliderPoint.getPosition().x-this-> sliderBar.getPosition().x;
    float sliderSize = this -> sliderBar.getSize().x;
    return sliderPos/sliderSize*100;
}

void Slider::setPercentage(float percentage)
{
    float percentToPos = this -> sliderBar.getSize().x/100.f*percentage;
    this-> sliderPoint.setPosition(this -> sliderBar.getPosition().x+percentToPos, this -> sliderPoint.getPosition().y);
}

void Slider::update(sf::RenderWindow* window)
{
    sf::Vector2i mousePos = sf::Mouse::getPosition(*window);
    sf::Vector2f mouseWindowPos = window->mapPixelToCoords(mousePos);
    if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)){
        if(this -> sliderPoint.getGlobalBounds().contains(mouseWindowPos)||this -> sliderBar.getGlobalBounds().contains(mouseWindowPos)){
            sliderMoving = true;
        }
    }
    else{
        this -> sliderMoving = false;
    }
    if(sliderMoving){
        this -> sliderPoint.setPosition(mouseWindowPos.x,this -> sliderPoint.getPosition().y);
    }
    if(this -> sliderPoint.getPosition().x < this -> sliderBar.getPosition().x){
        this -> sliderPoint.setPosition(this-> sliderBar.getPosition().x,this -> sliderPoint.getPosition().y);
    }
    if(this -> sliderPoint.getPosition().x > this -> sliderBar.getPosition().x+this -> sliderBar.getSize().x){
        this -> sliderPoint.setPosition(this -> sliderBar.getPosition().x+this -> sliderBar.getSize().x,this -> sliderPoint.getPosition().y);
    }
}

void Slider::setPosition(sf::Vector2f pos)
{
    this -> sliderBar.setPosition(pos);
    this -> sliderPoint.setPosition(pos);
}

void Slider::render(sf::RenderTarget *target)
{
    target->draw(this -> sliderBar);
    target->draw(this -> sliderPoint);
}
