#pragma once
#include "Level.h"
#include "Target.h"
#include "AirportMap.h"

class Level4 :
    public Level
{
private:
	F15& f15;
	Target* target;
	Map* map;
	bool end;

public:
	Level4(F15& F15, Map* Map);

	void Update(float dt) override;

	void Render(sf::RenderWindow& Window) override;

	bool IsEnd() override;

	void EndLevel(std::stack<Level*>& levels, std::stack<AnimScene*>* animScene) override;
};

