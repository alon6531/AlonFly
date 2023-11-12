#pragma once
#include <iostream>
#include <stack>
#include "SFML/Graphics.hpp"
#include "Button.h"
#include "Timer.h"
#include "F15.h"
#include"Map1.h"
#include "Mig29.h"
#include "Helicopter.h"
#include "AnimScene1.h"


class Level
{
private:


public:
	Level(F15& F15, Map* Map);

	virtual void Update(float dt) = 0;

	virtual void Render(sf::RenderWindow& Window) = 0;

	virtual bool IsEnd() = 0;
	virtual void EndLevel(std::stack<Level*>& levels, std::stack<AnimScene*>* animScene) = 0;
};

