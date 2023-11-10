#pragma once
#include "Entity.h"

class Projectile :
    public Entity
{
private:
    sf::Vector2i dir;

public:
    Projectile(const std::string& string, const sf::Vector2f& Pos, const sf::Vector2f& Scale, const sf::Vector2i Dir, float Speed);

    void Update(float dt);
};

