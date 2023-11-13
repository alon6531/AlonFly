#pragma once

#include "SFML/Graphics.hpp"
#include <iostream>

class Text
{
private:
	sf::Text text;
	sf::Font font;

public:
	Text();
	Text(const std::string& Str, const std::string& FontPath = "PixellettersFull.ttf");
	Text(const std::string& Str, const sf::Vector2f& Pos, const sf::Vector2f& Scale = sf::Vector2f(1, 1), 
		const sf::Color& Color = sf::Color::White, const std::string& FontPath = "PixellettersFull.ttf");

	void Render(sf::RenderWindow& window);

	void setString(const std::string& Str);

	sf::Text& GetText();
};

