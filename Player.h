#pragma once
#include "Entity.h"
#include "Projectile.h"
#include "Timer.h"


class Player :
    public Entity
{
private:
    sf::Vector2i dir;
    std::vector<Projectile*> leftProj;
    std::vector<Projectile*> rightProj;

    Timer* delay;

public:
    Player(const std::string& string, const sf::Vector2f& scale);

    void Update(float dt);

    void Render(sf::RenderWindow& Window);
};

