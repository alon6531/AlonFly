#pragma once

#include "SFML/Graphics.hpp"
#include "Timer.h"
#include <iostream>

class Explotion
{
private:
	sf::Sprite sprite;
	sf::Texture textrue;
	Timer* timer;
	bool isEnd = false;
public:
	Explotion(const sf::Vector2f& PosS, const sf::Vector2f& Scale);

	void Update(float dt);

	void Render(sf::RenderWindow& Window);

	bool IsEnd();
};

