#include "GameState.h"

GameState::GameState()
{
	f15 = new F15(sf::Vector2f(100, 100));

	texture.loadFromFile("Image/Sky.png");
	bg.setTexture(texture);
	bg.setScale(sf::Vector2f(2.2, 2));
}

void GameState::Update(float dt, std::stack<State*>& states)
{
	f15->Update(dt);
}

void GameState::Render(sf::RenderWindow& window)
{
	window.draw(bg);
	f15->Render(window);
}


