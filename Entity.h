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
	Entity(const std::string& string, const sf::Vector2f& Pos, const sf::Vector2f& Scale);

	sf::Sprite& Sprite();

	void AddMoveComponent(float MoveSpeed);
	void AddHitBoxComponent();

	bool IsCollide(const sf::FloatRect& Rect);
	void Update(float dt);

	void Render(sf::RenderWindow& window);

	void Move(float dt, const sf::Vector2i& Dir);
};

