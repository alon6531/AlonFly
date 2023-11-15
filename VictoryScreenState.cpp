#include "VictoryScreenState.h"

VictoryScreenState::VictoryScreenState()
{
	this->playAgain = new Button(sf::Vector2f(480, 400), sf::Vector2f(0.1, 0.1), "Image/PlayAgainB.png");
	endState = false;
	map = new AirportMap();

	title = new Text("VICTORY", sf::Vector2f(550, 100), sf::Vector2f(2, 2), sf::Color::Black);

}

void VictoryScreenState::Update(float dt, std::stack<State*>& states)
{
	if (this->playAgain->IsTrigger()) {
		std::cout << "pressed";
		states.push(new MainMenuState());
	}
	map->Update(dt);
}

void VictoryScreenState::Render(sf::RenderWindow& window)
{
	map->Render(window);
	playAgain->Render(window);
	title->Render(window);
}
