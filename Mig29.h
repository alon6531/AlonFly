#pragma once
#include "Plane.h"
#include "Projectile.h"
#include "Timer.h"
#include <time.h>

class Mig29 :
    public Plane
{
private:
    Timer* delay;
    int rand = 1;
public:
    Mig29(const sf::Vector2f& Pos);

    void Update(float dt, sf::Sprite* TargetSprite) override;

    void Render(sf::RenderWindow& Window) override;

};

