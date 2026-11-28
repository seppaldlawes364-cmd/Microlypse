#include "States/State.h"
#include "States/Menu.h" 
#include "States/GameState.h"
#include <iostream>
class Game{
private:
    float dt;
    sf::RenderWindow *window;
    sf::Event event;
    sf::Clock clock;

    States currentState = menu;
    State *state;

    GamePack *gamePack;

    void initWindow();
    void initPacks();

    void update();
    void updateDt();
    void pollEvent();
    void manageStates();

    void render();
public:
    Game();
    ~Game();
    void run();
};