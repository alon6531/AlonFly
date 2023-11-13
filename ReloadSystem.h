#pragma once

#include "SFML/Graphics.hpp"
#include <iostream>
#include "Timer.h"
#include "Text.h"

class ReloadSystem
{
private:
	int maxMagazine;
	int magazine;

	Timer* reloadTime;
	Text* text;


public:
	ReloadSystem(int MaxMagazine, float ReloadTime, const sf::Vector2f& Pos);

	void Update(float dt);

	void Shoot();

	bool IsCanShoot();

	void Render(sf::RenderWindow& Window);
};

