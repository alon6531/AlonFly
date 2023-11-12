#include "GameEngine.h"

GameEngine::GameEngine()
{
	window = new sf::RenderWindow(sf::VideoMode(1280, 720), "AlonFly", sf::Style::Close);
	dt = 0;

    states.push(new MainMenuState());
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
    this->states.top()->Update(this->dt, this->states);

    dt = clock.restart().asSeconds();
}

void GameEngine::Render()
{
    this->window->clear();

    this->states.top()->Render(*this->window);


    this->window->display();
}

void GameEngine::Run()
{
    while (this->window->isOpen()) {
        this->Update();

        this->Render();
    }
}

