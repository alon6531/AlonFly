#include "DieScreenState.h"

DieScreenState::DieScreenState()
{
	this->playAgain = new Button(sf::Vector2f(480, 400), sf::Vector2f(0.1, 0.1), "Image/PlayAgainB.png");
	endState = false;
	map = new AirportMap();

	title = new Text("GAME OVER", sf::Vector2f(520, 100), sf::Vector2f(2, 2), sf::Color::Black);
}

void DieScreenState::Update(float dt, std::stack<State*>& states)
{
	if (this->playAgain->IsTrigger()) {
		std::cout << "pressed";
		states.push(new MainMenuState());
	}
	map->Update(dt);
}

void DieScreenState::Render(sf::RenderWindow& window)
{
	map->Render(window);
	playAgain->Render(window);
	title->Render(window);
}
