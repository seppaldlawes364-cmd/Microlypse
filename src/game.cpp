#include "../game.h"

void Game::initWindow()
{
    window = new sf::RenderWindow(sf::VideoMode(1920,1100),"Micropolypse");
    window->setVerticalSyncEnabled(false);
    window->setFramerateLimit(60);
}

void Game::initPacks()
{
    gamePack = new GamePack{*window,*window,event,dt};
}

void Game::update()
{
    updateDt();
    pollEvent();
    state->update();
}

void Game::updateDt()
{
    dt = clock.restart().asSeconds();
}

void Game::pollEvent()
{
    while(window->pollEvent(event)){
        switch (event.type)
        {
        case sf::Event::Closed:
            window->close();
            break;
        
        default:
            break;
        }
    }
}

void Game::manageStates()
{

}

void Game::render()
{
    window->clear(sf::Color(186,176,149));

    state->render(window);

    window->display();
}

Game::Game()
{
    initWindow();
    initPacks();
    currentState = States::menu;
    state = new Menu{*gamePack};
}

void Game::run()
{
    while(window->isOpen()){
        update();
        render();
    }
}