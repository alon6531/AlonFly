#include "Projectile.h"

Projectile::Projectile(const std::string& string, const sf::Vector2f& Pos, const sf::Vector2f& Scale, float Speed)
	: Entity(string, Pos, Scale)
{
	AddMoveComponent(Speed);
	AddHitBoxComponent();
}

void Projectile::Update(float dt)
{

	Move(dt, sf::Vector2i(1, 0));

	Entity::Update(dt);
}
