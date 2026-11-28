#include "../Entities/Tile.h"
#include <vector>
#include <memory>
#include <SFML/Graphics.hpp>
struct TileMap
{
    sf::Vector2u size{100,100};
    sf::Vector2u renderSizeFromCam{5,5};
    std::vector<Tile> tiles;
    void render(sf::RenderTarget *target,sf::Vector2u camPos);
    TileMap(char pathToFile[32],char pathToTileSet[32]);
};