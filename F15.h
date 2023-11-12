#pragma once
#include "Plane.h"
#include "Projectile.h"
#include "Timer.h"

class F15 :
    public Plane
{
private:

public:
    F15(const sf::Vector2f& Pos);

    void Update(float dt);

    void Render(sf::RenderWindow& Window);
};

