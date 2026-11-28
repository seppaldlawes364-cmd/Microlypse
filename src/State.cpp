#include "../States/State.h"

void State::initBackground(std::string pathToFile)
{
    backgroundTex.loadFromFile(pathToFile);
    background.setTexture(backgroundTex);
}

void State::update()
{
}

void State::render(sf::RenderTarget* target)
{
}

States State::newState()
{
    return stateOverride;
}

State::State(GamePack& gamePack) : gamePack(gamePack)
{

}