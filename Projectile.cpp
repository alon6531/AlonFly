#include "Projectile.h"

Projectile::Projectile(const std::string& string, const sf::Vector2f& Pos, const sf::Vector2f& Scale, const sf::Vector2i Dir, float Speed)
	: Entity(string, Pos, Scale)
{
	dir = Dir;
	AddMoveComponent(Speed);
	AddHitBoxComponent();
}

void Projectile::Update(float dt)
{
	if (dir == sf::Vector2i(-1, 0)) {
		Move(dt, sf::Vector2i(-1, 0));
	}
	else if (dir == sf::Vector2i(1, 0)) {
		Move(dt, sf::Vector2i(1, 0));
	}
	else if (dir == sf::Vector2i(0, 1)) {
		Move(dt, sf::Vector2i(0, 1));
	}
	else if (dir == sf::Vector2i(0, -1)) {
		Move(dt, sf::Vector2i(0, -1));
	}

	

	Entity::Update(dt);
}
