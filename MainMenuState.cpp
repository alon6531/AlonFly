#include "MainMenuState.h"
#

MainMenuState::MainMenuState()
{
	this->startB = new Button(sf::Vector2f(480, 500), sf::Vector2f(0.1, 0.1), "Image/StartB.png");
	endState = false;
	map = new Map1();

	title = new Text("ALON FLY", sf::Vector2f(550, 300), sf::Vector2f(2, 2), sf::Color::Black);
}

void MainMenuState::Update(float dt, std::stack<State*>& states)
{
	if (this->startB->IsTrigger()) {
		std::cout << "pressed";
		states.push(new GameState());
	}
	map->Update(dt);
	
}

void MainMenuState::Render(sf::RenderWindow& window)
{
	map->Render(window);
	startB->Render(window);
	title->Render(window);
}


