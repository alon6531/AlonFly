#pragma once

#include "SFML/Graphics.hpp"

class HitBoxComponent
{
private:
	sf::Sprite& sprite;
	sf::RectangleShape hitBox;



public:
	HitBoxComponent(sf::Sprite& sprite);

	bool IsCollide(const sf::FloatRect& rect);
	void Update();

	void Render(sf::RenderWindow& window);
};

