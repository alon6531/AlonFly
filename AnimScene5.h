#pragma once
#include "AnimScene.h"
#include "Target.h"
#include "Map3.h"
#include "Level4.h"
#include "AnimScene4.h"

class AnimScene5 :
    public AnimScene
{
private:
    sf::Sprite f15;
    sf::Texture f15Texture;
    Map* map;
    float speed;
    bool end;
    Timer* f15Land;

public:
    AnimScene5();

    void Update(float dt) override;
    void Render(sf::RenderWindow& Window) override;

    bool IsEnd() override;
};

