#pragma once

#include"SFML/Graphics.hpp"
#include <iostream>
#include "Timer.h"

class EngineComponent
{
private:
	sf::Sprite& sprite;
	sf::Sprite left;
	sf::Sprite right;
	sf::Texture texture;
	sf::Vector2f posL;
	sf::Vector2f posR;
	sf::Vector2f scale;

	Timer* timer;
public:
	EngineComponent(sf::Sprite& Sprite, const std::string& string, const sf::Vector2f& PosL, const sf::Vector2f& PosR, const sf::Vector2f& Scale);
	void StartEngine();

	void Update(float dt);
	void Render(sf::RenderWindow& Window);

	void SetPos(const sf::Vector2f& PosL, const sf::Vector2f& PosR);
};

