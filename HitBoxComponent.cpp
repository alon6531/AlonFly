#include "HitBoxComponent.h"

HitBoxComponent::HitBoxComponent(sf::Sprite& sprite)
	: sprite(sprite)
{
	hitBox.setPosition(this->sprite.getPosition().x, this->sprite.getPosition().y);
	hitBox.setRotation(sprite.getRotation());
	hitBox.setSize(sf::Vector2f(sprite.getGlobalBounds().width, sprite.getGlobalBounds().height));
	hitBox.setFillColor(sf::Color::Transparent);
	hitBox.setOutlineThickness(-1.f);
	hitBox.setOutlineColor(sf::Color::Green);
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
}

void HitBoxComponent::Render(sf::RenderWindow& window)
{
	window.draw(hitBox);
}
