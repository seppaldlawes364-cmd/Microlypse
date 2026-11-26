#include "../game.h"

void Game::initWindow()
{
    window = new sf::RenderWindow(sf::VideoMode(1920,1100),"Microlypse");
    window->setVerticalSyncEnabled(false);
    window->setFramerateLimit(60);
}

void Game::initPacks()
{
    gamePack = new GamePack{*window,event,dt};
}

void Game::update()
{
    updateDt();
    pollEvent();
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

void Game::render()
{
    window->clear(sf::Color::Blue);

    window->display();
}

Game::Game()
{
    initWindow();
    initPacks();
}

void Game::run()
{
    while(window->isOpen()){
        update();
        render();
    }
}