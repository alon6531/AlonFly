#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>
#include <cstdlib>

class Map
{
private:


public:
	Map();

	virtual void Update(float dt) = 0;

	virtual void Render(sf::RenderWindow& Window) = 0;
};

