#include "Bomb.h"


Bomb::Bomb(const std::string& string, const sf::Vector2f& Pos, const sf::Vector2f& Scale, float Speed) : Projectile(string, Pos, Scale, Speed)
{
	speed = Speed;
}

void Bomb::Update(float dt, bool L_R)
{
	Sprite().move(speed * dt * 1.5, speed * dt);

	Projectile::Update(dt, L_R);
}


