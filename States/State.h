#pragma once
#include "../UsableThings/Button.h"
#include "../UsableThings/Slider.h"
#include "../Structs/gamePack.h"
enum States{
    menu
};
class State{
protected:
    sf::Font sans;
    GamePack& gamePack;
    States stateOverride;
public:
    virtual void update();
    virtual void render(sf::RenderTarget* target);
    States newState();
    State(GamePack& gamePack);
};