#pragma once
#include "AnimScene.h"
#include "AirportMap.h"
#include "Timer.h"
#include <math.h>


class AnimScene1 :
    public AnimScene
{
private:
    sf::Sprite sprite;
    sf::Texture texture;
    bool moveForword;
    sf::Sprite boeing;
    sf::Texture boeingTexture;
    Map* map;
    bool end;

    Timer* takeOf;
public:
    AnimScene1();

    void Update(float dt) override;
    void Render(sf::RenderWindow& Window) override;

    bool IsEnd() override;
};

