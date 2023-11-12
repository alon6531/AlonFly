#include "HitBoxComponent.h"

HitBoxComponent::HitBoxComponent(sf::Sprite& sprite)
	: sprite(sprite)
{
	hitBox.setPosition(this->sprite.getPosition().x, this->sprite.getPosition().y);
	hitBox.setSize(sf::Vector2f(sprite.getGlobalBounds().width, sprite.getGlobalBounds().height));
	hitBox.setFillColor(sf::Color::Transparent);
	hitBox.setOutlineThickness(-1.f);
	hitBox.setOutlineColor(sf::Color::Green);

	cantExitScreen = false;
}

bool HitBoxComponent::IsCollide(const sf::FloatRect& rect)
{
	return hitBox.getGlobalBounds().intersects(rect);
}

void HitBoxComponent::Update()
{
	hitBox.setSize(sf::Vector2f(sprite.getGlobalBounds().width, sprite.getGlobalBounds().height));

	if (sprite.getOrigin() != sf::Vector2f(0, 0))
		hitBox.setPosition(this->sprite.getPosition().x - sprite.getGlobalBounds().width / 2,
			this->sprite.getPosition().y - sprite.getGlobalBounds().height / 2);
	else
		hitBox.setPosition(this->sprite.getPosition().x, this->sprite.getPosition().y);

	if (cantExitScreen) {
		if (sprite.getPosition().y < sprite.getGlobalBounds().height / 2)
		{
			sprite.setPosition(sf::Vector2f(sprite.getPosition().x , sprite.getGlobalBounds().height / 2));
		}
		else if (sprite.getPosition().y + sprite.getGlobalBounds().height / 2  > 720) {
			sprite.setPosition(sf::Vector2f(sprite.getPosition().x, 720 - hitBox.getGlobalBounds().height / 2));
		}
		else if (sprite.getPosition().x < sprite.getGlobalBounds().width / 2) {
			sprite.setPosition(sf::Vector2f(sprite.getGlobalBounds().width /2, sprite.getPosition().y));
		}
		else if (sprite.getPosition().x + sprite.getGlobalBounds().width / 2 > 1280) {
			sprite.setPosition(sf::Vector2f(1280- sprite.getGlobalBounds().width / 2, sprite.getPosition().y));
		}
	}
}

void HitBoxComponent::Render(sf::RenderWindow& window)
{
	window.draw(hitBox);
}

void HitBoxComponent::SetCantExitScreen()
{
	cantExitScreen = true;
}
