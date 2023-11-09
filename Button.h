#pragma once

#include "SFML/Graphics.hpp"
#include <iostream>

class Button
{
private:
	sf::RectangleShape obj;
	sf::Vector2f& pos;
	sf::Vector2f& size;
	sf::Texture* texture;

	sf::Text text;
	sf::Font font;

public:
	Button(sf::Vector2f Pos, sf::Vector2f Size, sf::Color Color = sf::Color::Red, std::string Text = "");

	void Render(sf::RenderWindow& Window);
	bool IsTrigger();
	

};

