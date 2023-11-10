#pragma once

#include "MoveComponent.h"
#include "HitBoxComponent.h"

class Entity
{
private:
	sf::Sprite sprite;
	sf::Texture texture;
	MoveComponent* moveComponent;
	HitBoxComponent* hitBoxComponent;

public:
	Entity(const std::string& string, const sf::Vector2f& scale = sf::Vector2f(100, 100));

	void AddMoveComponent(float MoveSpeed);
	void AddHitBoxComponent();

	void Update(float dt);

	void Render(sf::RenderWindow& window);
};

