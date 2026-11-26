#include "../States/State.h"

void State::update()
{
}

void State::render()
{
}

States State::newState()
{
    return stateOverride;
}

State::State(GamePack gamePack) : gamePack(gamePack)
{

}