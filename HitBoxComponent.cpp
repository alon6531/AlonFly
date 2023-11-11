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
		if (hitBox.getPosition().y < 0)
		{
			sprite.setPosition(sf::Vector2f(sprite.getPosition().x , 60));
		}
		else if (sprite.getPosition().y + hitBox.getGlobalBounds().height > 780) {
			sprite.setPosition(sf::Vector2f(sprite.getPosition().x, 720 - hitBox.getGlobalBounds().height + 50));
		}
		else if (hitBox.getPosition().x < 0) {
			sprite.setPosition(sf::Vector2f(60, sprite.getPosition().y));
		}
		else if (hitBox.getPosition().x + hitBox.getGlobalBounds().width > 1280) {
			sprite.setPosition(sf::Vector2f(1280- sprite.getGlobalBounds().width + 50, sprite.getPosition().y));
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
