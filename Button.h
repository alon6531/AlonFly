#pragma once

#include "SFML/Graphics.hpp"
#include <iostream>

class Button
{
private:
	sf::Sprite obj;
	sf::Vector2f& pos;
	sf::Vector2f& size;
	sf::Texture* texture;
	sf::RenderWindow* window;

	sf::Text text;
	sf::Font font;

public:
	Button(sf::Vector2f Pos, sf::Vector2f Size, sf::Color Color = sf::Color::Red, std::string Text = "");
	Button(sf::Vector2f Pos, sf::Vector2f Size, const std::string& Str);

	void Render(sf::RenderWindow& Window);
	bool IsTrigger();
	

};

