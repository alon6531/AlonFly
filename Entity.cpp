#include "Entity.h"

Entity::Entity(const std::string& string, const sf::Vector2f& scale)
{
	if (!texture.loadFromFile(string))
		std::cout << "CANT_LOAD_TEXTURE \n";
	sprite.setTexture(texture);

	sprite.setOrigin(sprite.getGlobalBounds().width / 2, sprite.getGlobalBounds().height / 2);
	sprite.setScale(sf::Vector2f(scale.x / 100, scale.y / 100));

	moveComponent = NULL;
}

void Entity::AddMoveComponent(float MoveSpeed)
{
	moveComponent = new MoveComponent(sprite, MoveSpeed);
}

void Entity::AddHitBoxComponent()
{
	hitBoxComponent = new HitBoxComponent(sprite);
}

void Entity::Update(float dt)
{
	if (moveComponent) {
		moveComponent->Update(dt);
	}

	if (hitBoxComponent) {
		hitBoxComponent->Update();
	}
}

void Entity::Render(sf::RenderWindow& window)
{
	window.draw(sprite);

	if (hitBoxComponent) {
		hitBoxComponent->Render(window);
	}
}
