#include "Structs/gamePack.h"
#include <iostream>
class Game{
private:
    float dt;
    sf::RenderWindow *window;
    sf::Event event;
    sf::Clock clock;

    GamePack *gamePack;

    void initWindow();
    void initPacks();

    void update();
    void updateDt();
    void pollEvent();

    void render();
public:
    Game();
    void run();
};