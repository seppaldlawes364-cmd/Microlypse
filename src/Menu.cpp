#include "../States/Menu.h"

void Menu::update()
{
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
        if(gameButton.mouseCollision(&gamePack.window)){
            std::cout << "sudo rm -r /" << std::endl;
        }
        else{
            std::cout << "fuhkaing worhks" << std::endl;
        }
    }
    
    std::cout << "1" << std::endl;
}

void Menu::render(sf::RenderTarget* target)
{
    gameButton.render(target);
}

Menu::Menu(GamePack &gamePack) : State(gamePack)
{
    sans.loadFromFile("../Fonts/Sans_Big.ttf");
    gameButton.setFont(sans);
    gameButton.setPosition({static_cast<float>(gamePack.window.getSize().x/2),static_cast<float>(gamePack.window.getSize().y/2)});
    gameButton.setString("Start Game");
    gameButton.setTextScale(2);
}