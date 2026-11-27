#include "../States/TileMap.h"

void TileMap::render(sf::RenderTarget *target)
{
    for(int i = 0; i < tiles.size(); i++){
        tiles[i].render(target);
    }
}