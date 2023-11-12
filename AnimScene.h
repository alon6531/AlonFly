#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>

class AnimScene
{
private:


public:
	AnimScene();

	virtual void Update(float dt) = 0;
	virtual void Render(sf::RenderWindow& Window) = 0;

	virtual bool IsEnd() = 0;
};

