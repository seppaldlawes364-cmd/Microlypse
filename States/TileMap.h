#include "../Entities/Tile.h"
#include <vector>
#include <SFML/Graphics.hpp>
struct TileMap
{
    sf::Vector2u size;
    std::vector<Tile> tiles;
    void render(sf::RenderTarget* target);
};