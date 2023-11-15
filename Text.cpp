#include "Text.h"

Text::Text()
{
}

Text::Text(const std::string& Str, const std::string& FontPath)
{
	
	text.setString(Str);
	text.setFillColor(sf::Color::White);
	text.scale(1, 1);
	font.loadFromFile(FontPath);
	text.setFont(font);
}

Text::Text(const std::string& Str, const sf::Vector2f& Pos, const sf::Vector2f& Scale, const sf::Color& Color, const std::string& FontPath)
{
	text.setString(Str);
	text.setPosition(Pos);
	text.setScale(Scale);
	text.setFillColor(Color);
	font.loadFromFile(FontPath);
	text.setFont(font);
	text.setOutlineThickness(0.5);
	text.setOutlineColor(sf::Color::Cyan);

}

void Text::Render(sf::RenderWindow& window)
{
	window.draw(text);
}

void Text::setString(const std::string& Str)
{
	text.setString(Str);
}

sf::Text& Text::GetText()
{
	return text;
}



