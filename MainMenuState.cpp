#include "MainMenuState.h"
#include "GameState.h"

MainMenuState::MainMenuState()
{
	this->startB = new Button(sf::Vector2f(300, 600), sf::Vector2f(150, 75), sf::Color::Red, "Play");
	endState = false;
}

void MainMenuState::Update(float dt, State& state)
{
	if (this->startB->IsTrigger()) {
		std::cout << "pressed";
		
	}

	state = GameState();
}

void MainMenuState::Render(sf::RenderWindow& window)
{
	startB->Render(window);
}


