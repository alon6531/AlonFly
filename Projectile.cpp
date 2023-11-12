#include "Projectile.h"


Projectile::Projectile(const std::string& string, const sf::Vector2f& Pos, const sf::Vector2f& Scale, float Speed)
	: Entity(string, Pos, Scale)
{
	AddMoveComponent(Speed);
	AddHitBoxComponent();
	Sprite().setRotation(90);

	killTime = new Timer(5);
	bDead = false;
}

void Projectile::Update(float dt, bool L_R)
{
	if(L_R == true)
		Move(dt, sf::Vector2i(1, 0));
	else
		Move(dt, sf::Vector2i(-1, 0));

	killTime->Update(dt);

	if (killTime->IsEnd())
		bDead = true;

	Entity::Update(dt);
}

const sf::FloatRect& Projectile::rect()
{
	return Sprite().getGlobalBounds();
}

bool Projectile::IsDead()
{
	return bDead;
}
