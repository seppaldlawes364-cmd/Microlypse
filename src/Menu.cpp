#include "../States/Menu.h"

void Menu::update()
{
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
        if(gameButton.mouseCollision(&gamePack.window)){
            stateOverride = States::game;
        }
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
        stateOverride = States::EXIT;
    }
}

void Menu::render(sf::RenderTarget* target)
{
    target->draw(background);
    gameButton.render(target);
    
}

Menu::Menu(GamePack &gamePack) : State(gamePack)
{
    stateOverride = menu;
    sans.loadFromFile("../Fonts/Sans_Big.ttf");
    gameButton.setFont(sans);
    gameButton.setPosition({static_cast<float>(gamePack.window.getSize().x/2),(static_cast<float>(gamePack.window.getSize().y/5))});
    gameButton.setString("Start Game");
    gameButton.setTextScale(2);
    initBackground("../Textures/MainBackground.png");
    background.scale(16,16);
    sf::Vector2f backSize = background.getLocalBounds().getSize();
    background.setOrigin(backSize.x/2,backSize.y/2);
    background.setPosition({static_cast<float>(gamePack.window.getSize().x/2),static_cast<float>(gamePack.window.getSize().y/2)});
}