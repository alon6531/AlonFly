#pragma once
#include "Entity.h"
#include "Projectile.h"
#include "Timer.h"

class F15 :
    public Entity
{
private:
    sf::Vector2i dir;
    std::vector<Projectile*> leftProj;
    std::vector<Projectile*> rightProj;

    Timer* delay;
public:
    F15(const sf::Vector2f& Pos);

    void Update(float dt);

    void Render(sf::RenderWindow& Window);
};

