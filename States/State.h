#pragma once
#include <vector>
#include <stab.h>
#include "../UsableThings/Button.h"
#include "../UsableThings/Slider.h"
#include "../Structs/gamePack.h"
enum States{
    menu,
    game,
    EXIT
};
class State{
protected:
    sf::Texture backgroundTex;
    sf::Sprite background;
    sf::Font sans;
    GamePack& gamePack;
    States stateOverride;
    void initBackground(std::string pathToFile);
public:
    virtual void update();
    virtual void render(sf::RenderTarget* target);
    States newState();
    State(GamePack& gamePack);
};