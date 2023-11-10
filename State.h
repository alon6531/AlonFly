#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>
#include <stack>

class State
{
private:


public:
	State();
	virtual void Update(float dt, std::stack<State*>& states)= 0;

	virtual void Render(sf::RenderWindow& window) = 0;


};

