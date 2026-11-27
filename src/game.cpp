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
    manageStates();
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
    if(currentState != state->newState()){
        currentState = state->newState();
        switch (state->newState())
        {
        case menu:
            std::cout << "Menu" << std::endl;
            delete state;
            state = new Menu{*gamePack};
            break;
        case game:
            std::cout << "Game" << std::endl;
            delete state;
            state = new GameState{*gamePack};
            break;
        default:
            break;
        }
    }
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