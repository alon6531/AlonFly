#include "MoveComponent.h"

MoveComponent::MoveComponent(sf::Sprite& Sprite, float MoveSpeed)
	: sprite(Sprite)
{

	moveSpeed = MoveSpeed;

}

void MoveComponent::MoveLeft(float dt)
{
	sprite.move(-moveSpeed * dt, 0);

}

void MoveComponent::MoveRight(float dt)
{
	sprite.move(moveSpeed* dt, 0);

}

void MoveComponent::MoveUp(float dt)
{
	sprite.move(0, -moveSpeed * dt);

}

void MoveComponent::MoveDown(float dt)
{
	sprite.move(0, moveSpeed* dt);

}

void MoveComponent::SetSpeed(float Speed)
{
	moveSpeed = Speed;
}
