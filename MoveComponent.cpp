#include "MoveComponent.h"

MoveComponent::MoveComponent(sf::Sprite& Sprite, float MoveSpeed)
	: sprite(Sprite)
{

	moveSpeed = MoveSpeed;
}

void MoveComponent::MoveLeft(float dt)
{
	sprite.move(-moveSpeed * dt, 0);
	sprite.setRotation(-90);
}

void MoveComponent::MoveRight(float dt)
{
	sprite.move(moveSpeed* dt, 0);
	sprite.setRotation(90);
}

void MoveComponent::MoveUp(float dt)
{
	sprite.move(0, -moveSpeed * dt);
	sprite.setRotation(0);
}

void MoveComponent::MoveDown(float dt)
{
	sprite.move(0, moveSpeed* dt);
	sprite.setRotation(180);
}
