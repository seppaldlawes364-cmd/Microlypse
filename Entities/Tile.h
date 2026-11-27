#include <SFML/Graphics.hpp>
struct Tile
{
    sf::Texture& tex;
    sf::Sprite sprite;
    sf::Vector2f position;
    Tile(sf::Texture& tex,sf::Vector2f pos);
    void render(sf::RenderTarget* target);
};
