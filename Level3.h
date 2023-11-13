#pragma once
#include "Level.h"
#include "Target.h"
#include "Map3.h"

class Level3 :
    public Level
{
private:
	F15& f15;
	std::vector<Target*> targets;
	std::vector<Target*> targets2;
	Map* map;
	bool end;

public:
	Level3(F15& F15, Map* Map);

	void Update(float dt) override;

	void Render(sf::RenderWindow& Window) override;

	bool IsEnd() override;

	void EndLevel(std::stack<Level*>& levels, std::stack<AnimScene*>* animScene) override;
};

