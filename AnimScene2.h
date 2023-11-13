#pragma once
#include "AnimScene.h"
#include "Map1.h"

class AnimScene2 :
    public AnimScene
{
private:
    sf::Sprite f15;
    sf::Texture f15Texture;
    sf::Sprite mig29;
    sf::Texture mig29Texture;
    Map* map;
    bool end;

    Timer* f15MoveForword;
    Timer* mig29MoveTof15;
    Timer* mig29MoveForword;
public:
    AnimScene2();

    void Update(float dt) override;
    void Render(sf::RenderWindow& Window) override;

    bool IsEnd() override;
};

