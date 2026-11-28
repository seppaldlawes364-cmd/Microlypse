#include "../States/TileMap.h"

void TileMap::render(sf::RenderTarget *target,sf::Vector2u camPos)
{
    for(int i = 0;i<tiles.size(); i++){
        tiles[i].render(target);
    }

}

TileMap::TileMap(char pathToFile[32],char pathToTileSet[32])
{

}
