#include "Button.h"


Button::Button(sf::Vector2f Pos, sf::Vector2f Size, sf::Color Color, std::string Text)
	: pos(Pos), size(Size)
{
	this->obj.setPosition(sf::Vector2f(this->pos.x - this->size.x / 2, this->pos.y - this->size.y / 2));
	this->obj.setSize(this->size);
	this->obj.setFillColor(Color);
	texture = NULL;
	window = NULL;

	font.loadFromFile("PixellettersFull.ttf");
	text.setPosition(obj.getPosition());
	text.setFont(font);
	text.setScale(obj.getSize().x * 0.02, obj.getSize().y * 0.02);
	text.setFillColor(sf::Color::Yellow);
	text.setString(Text);
}

void Button::Render(sf::RenderWindow& Window)
{
	window = &Window;
	Window.draw(obj);
	Window.draw(text);

}

bool Button::IsTrigger()
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		sf::Vector2f mousePos = sf::Vector2f(sf::Mouse::getPosition(*window).x, sf::Mouse::getPosition(*window).y);
		if (mousePos.x > this->obj.getPosition().x &&
			mousePos.x < this->obj.getPosition().x + this->obj.getSize().x)
		{
			if (mousePos.y > this->obj.getPosition().y &&
				mousePos.y < this->obj.getPosition().y + this->obj.getSize().y)
			{
				return true;
			}
		}
	}
	

	return false;
}
