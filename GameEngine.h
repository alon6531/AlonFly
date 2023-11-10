#pragma once

#include "SFML/Graphics.hpp"
#include <iostream>
#include "MainMenuState.h"
#include "GameState.h"
#include <stack>

class GameEngine
{
private:
	sf::RenderWindow* window;
	float dt;
	std::stack<State*> states;

public:
	GameEngine();
	~GameEngine();

	void WinEvent();
	void Update();
	void Render();

	void Run();

};

