#pragma once
#include "AnimScene.h"
#include "Target.h"
#include "Map1.h"

class AnimScene3 :
    public AnimScene
{
private:
    sf::Sprite f15;
    sf::Texture f15Texture;
    Map* map;
    float speed;
    bool end;
    Timer* f15MoveDown;

public:
    AnimScene3();

    void Update(float dt) override;
    void Render(sf::RenderWindow& Window) override;

    bool IsEnd() override;
};

