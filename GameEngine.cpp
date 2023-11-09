#include "GameEngine.h"

GameEngine::GameEngine()
{
	window = new sf::RenderWindow(sf::VideoMode(600, 700), "AlonFly", sf::Style::Default);
	dt = 0;

    state = new MainMenuState();
}

GameEngine::~GameEngine()
{
}

void GameEngine::WinEvent()
{
    sf::Event winEv;
    while (this->window->pollEvent(winEv))
    {
        if (winEv.type == sf::Event::Closed) {
            this->window->close();
            std::cout << "Window Closed" << std::endl;
        }
            
    }


}

void GameEngine::Update()
{
	this->WinEvent();
    this->state->Update(this->dt, *this->state);
}

void GameEngine::Render()
{
    this->window->clear();

    this->state->Render(*this->window);


    this->window->display();
}

void GameEngine::Run()
{
    while (this->window->isOpen()) {
        this->Update();

        this->Render();
    }
}

