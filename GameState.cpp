#include "GameState.h"

GameState::GameState()
{
	f15 = new F15(sf::Vector2f(0, 0));

}

void GameState::Update(float dt, std::stack<State*>& states)
{
	f15->Update(dt);
}

void GameState::Render(sf::RenderWindow& window)
{
	f15->Render(window);
}


