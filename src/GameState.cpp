#include "../States/GameState.h"

void GameState::initMap()
{
    
}

void GameState::update()
{
}

void GameState::render(sf::RenderTarget *target)
{
}

GameState::GameState(GamePack &gamePack): State(gamePack)
{
    stateOverride = States::game;
}
