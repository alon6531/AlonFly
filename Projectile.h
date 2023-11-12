#pragma once
#include "Entity.h"
#include "Timer.h"

class Projectile :
    public Entity
{
private:
    Timer* killTime;
    bool bDead;
public:
    Projectile(const std::string& string, const sf::Vector2f& Pos, const sf::Vector2f& Scale, float Speed);

    void Update(float dt, bool L_R);

    const sf::FloatRect& rect();

    bool IsDead();
};

