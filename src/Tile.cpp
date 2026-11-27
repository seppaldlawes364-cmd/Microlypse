#include "../Entities/Tile.h"

Tile::Tile(sf::Texture &tex,sf::Vector2f pos = {0,0}) :tex(tex)
{
    sprite.setTexture(tex);
    sprite.setPosition(pos);
}

void Tile::render(sf::RenderTarget *target)
{
    target->draw(sprite);
}
