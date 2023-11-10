#include "MainMenuState.h"
#include "GameState.h"

MainMenuState::MainMenuState()
{
	this->startB = new Button(sf::Vector2f(610, 600), sf::Vector2f(150, 75), sf::Color::Red, "Play");
	endState = false;



	title = new Text("*AlonFly*", sf::Vector2f(580, 300));
}

void MainMenuState::Update(float dt, std::stack<State*>& states)
{
	if (this->startB->IsTrigger()) {
		std::cout << "pressed";
		states.push(new GameState());
	}

	
}

void MainMenuState::Render(sf::RenderWindow& window)
{

	startB->Render(window);
	title->Render(window);
}


