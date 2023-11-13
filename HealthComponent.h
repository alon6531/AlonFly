#pragma once
#include "SFML/Graphics.hpp"
#include "Text.h"
class HealthComponent
{
private:
	int currentHealth;
	int maxHealth;
	sf::Sprite& sprite;
	sf::Text healthText;
	sf::RectangleShape healthBarFrame;
	sf::RectangleShape healthBar;
	std::vector<Text*> damageText;
public:
	HealthComponent(sf::Sprite& Sprite, int MaxHealth);

	void Update(float dt);

	void Render(sf::RenderWindow& Window);

	void OnHit(int Damage);

	int GetHealth();
};

