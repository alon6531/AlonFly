#include "MoveComponent.h"

MoveComponent::MoveComponent(sf::Sprite& Sprite, float MoveSpeed)
	: sprite(Sprite)
{

	moveSpeed = MoveSpeed / 100;
}

void MoveComponent::Update(float dt)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		sprite.move(-moveSpeed, 0);
		sprite.setRotation(-90);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		sprite.move(moveSpeed, 0);
		sprite.setRotation(90);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		sprite.move(0, -moveSpeed);
		sprite.setRotation(0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		sprite.move(0, moveSpeed);
		sprite.setRotation(180);
	}
}
