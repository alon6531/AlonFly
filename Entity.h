#pragma once

#include "MoveComponent.h"
#include "HitBoxComponent.h"
#include "HealthComponent.h"
#include "Timer.h"

class Entity
{
private:
	sf::Sprite sprite;
	sf::Texture texture;
	MoveComponent* moveComponent;
	HitBoxComponent* hitBoxComponent;
	HealthComponent* healthComponent;

public:
	Entity(const std::string& string, const sf::Vector2f& scale = sf::Vector2f(100, 100));
	Entity(const std::string& string, const sf::Vector2f& Pos, const sf::Vector2f& Scale);

	sf::Sprite& Sprite();

	void AddMoveComponent(float MoveSpeed);
	void AddHitBoxComponent();
	void AddHealthComponent(int MaxHealth);


	bool IsCollide(const sf::FloatRect& Rect);
	virtual void Update(float dt);

	virtual void Render(sf::RenderWindow& window);

	void Move(float dt, const sf::Vector2i& Dir);
	
	void CantExitScreen();

	int GetHealth();

	void OnHit(int Damage);

	void SetSpeed(float Speed);
	void SetTexture(const std::string& FilePath);
};

