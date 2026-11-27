#include "../States/Menu.h"

void Menu::update()
{
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
        if(gameButton.mouseCollision(&gamePack.window)){
            stateOverride = States::game;
        }
    }
}

void Menu::render(sf::RenderTarget* target)
{
    gameButton.render(target);
}

Menu::Menu(GamePack &gamePack) : State(gamePack)
{
    stateOverride = menu;
    sans.loadFromFile("../Fonts/Sans_Big.ttf");
    gameButton.setFont(sans);
    gameButton.setPosition({static_cast<float>(gamePack.window.getSize().x/2),static_cast<float>(gamePack.window.getSize().y/2)});
    gameButton.setString("Start Game");
    gameButton.setTextScale(2);
}