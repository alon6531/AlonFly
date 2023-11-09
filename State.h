#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>

class State
{
private:


public:
	State();
	virtual void Update(float dt, State& state)= 0;

	virtual void Render(sf::RenderWindow& window) = 0;


};

