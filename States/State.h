#pragma once
#include "../UsableThings/Button.h"
#include "../UsableThings/Slider.h"
#include "../Structs/gamePack.h"
enum States{
    menu
};
class State{
private:
    GamePack& gamePack;
    States stateOverride;
public:
    virtual void update();
    virtual void render();
    States newState();
    State(GamePack gamePack);
};