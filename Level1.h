#pragma once
#include "Level.h"
class Level1 :
    public Level
{

private:
	F15& f15;
	std::vector<Plane*> enemy;
	Map* map;
	bool end;

public:
	Level1(F15& F15, Map* Map);

	void Update(float dt) override;

	void Render(sf::RenderWindow& Window) override;

	bool IsEnd() override;

	void EndLevel(std::stack<Level*>& levels, std::stack<AnimScene*>* animScene) override;
};

