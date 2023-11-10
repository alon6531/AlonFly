#include "GameState.h"

GameState::GameState()
{
	player = new Entity("plane.png", sf::Vector2f(25, 25));
	player->AddHitBoxComponent();
	player->AddMoveComponent(10);
}

void GameState::Update(float dt, std::stack<State*>& states)
{
	player->Update(dt);
}

void GameState::Render(sf::RenderWindow& window)
{
	player->Render(window);
}


