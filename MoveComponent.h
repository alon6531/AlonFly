#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>

class MoveComponent
{
private:
	sf::Sprite& sprite;
	float moveSpeed;

public:
	MoveComponent(sf::Sprite& Sprite, float MoveSpeed);


	void MoveLeft(float dt);
	void MoveRight(float dt);
	void MoveUp(float dt);
	void MoveDown(float dt);
};

