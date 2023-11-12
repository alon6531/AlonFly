#pragma once
#include "Plane.h"
class Helicopter :
    public Plane
{
private:

    Timer* animDelay;
    sf::Vector2f StartPos;
    bool up_Down;

public:
    Helicopter(const sf::Vector2f& Pos);
    void Update(float dt, sf::Sprite* TargetSprite = NULL) override;

    void Render(sf::RenderWindow& Window);
};

