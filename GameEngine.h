#pragma once

#include "SFML/Graphics.hpp"
#include <iostream>
#include "MainMenuState.h"

class GameEngine
{
private:
	sf::RenderWindow* window;
	float dt;
	State* state;

public:
	GameEngine();
	~GameEngine();

	void WinEvent();
	void Update();
	void Render();

	void Run();

};

