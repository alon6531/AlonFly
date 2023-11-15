#pragma once

#include "AnimScene.h"
#include "Map3.h"
#include "AirportMap.h"
#include "Target.h"

class AnimScene4 :
    public AnimScene
{
private:
    sf::Sprite f15;
    sf::Texture f15Texture;
    Map* map;
    bool end;
    std::vector<Target*> targets;
    bool initLevel;
    Timer* f15MoveForword;
    Timer* f15MoveForword2;
public:
    AnimScene4();

    void Update(float dt) override;
    void Render(sf::RenderWindow& Window) override;

    bool IsEnd() override;
};

