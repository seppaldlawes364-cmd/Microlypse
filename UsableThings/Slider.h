#include <SFML/Graphics.hpp>
#include <iostream>
class Slider{
    private:
    bool sliderMoving = false;
    sf::CircleShape sliderPoint;
    sf::RectangleShape sliderBar;
    void initShapes();
    public:
    
    Slider();
    ~Slider();
    float getPercentage();
    void setPercentage(float percentage);
    void update(sf::RenderWindow* window);
    void setPosition(sf::Vector2f pos);
    void render(sf::RenderTarget* target);
};