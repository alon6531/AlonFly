#pragma once
#include "Projectile.h"
class Bomb :
    public Projectile
{
private:
    float speed;
public:
    Bomb(const std::string& string, const sf::Vector2f& Pos, const sf::Vector2f& Scale, float Speed);

    void Update(float dt, bool L_R) override;

};

