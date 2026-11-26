#include <SFML/Graphics.hpp>
struct GamePack
{
    sf::RenderWindow& window;
    sf::RenderTarget& target;
    sf::Event& event;
    float& dt;    
};
