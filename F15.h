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
    std::vector<Projectile*> bomb;

    Timer* bulletDelay;
    Timer* bombDelay;


public:
    F15(const sf::Vector2f& Pos);

    void Update(float dt);

    void Render(sf::RenderWindow& Window);
};

