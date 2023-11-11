#include "EngineComponent.h"



EngineComponent::EngineComponent(sf::Sprite& Sprite, const std::string& string, const sf::Vector2f& PosL, const sf::Vector2f& PosR, const sf::Vector2f& Scale)
	: sprite(Sprite)
{
	if (!texture.loadFromFile(string))
		std::cout << "CANT_LOAD_TEXTURE";
	left.setTexture(texture);
	right.setTexture(texture);
	
	left.setOrigin(sprite.getGlobalBounds().width / 2, sprite.getGlobalBounds().height / 2);
	right.setOrigin(sprite.getGlobalBounds().width / 2, sprite.getGlobalBounds().height / 2);
	left.setRotation(-90);
	right.setRotation(-90);

	scale = Scale;
	left.setScale(scale / 0.f);
	right.setScale(scale / 0.f);

	posL = PosL;
	posR = PosR;
	left.setPosition(sprite.getPosition() + PosL);
	right.setPosition(sprite.getPosition() + PosR);

	timer = new Timer(0.1);

	
}

void EngineComponent::StartEngine()
{
	left.setScale(scale);
	right.setScale(scale);
	timer->Reset();

}

void EngineComponent::Update(float dt)
{
	left.setPosition(sprite.getPosition() + posL);

	right.setPosition(sprite.getPosition() + posR);

	timer->Update(dt);

	if (timer->IsEnd()) {
		left.setScale(scale * 0.f);
		right.setScale(scale * 0.f);

	}
}

void EngineComponent::Render(sf::RenderWindow& Window)
{
	Window.draw(left);
	Window.draw(right);
}

void EngineComponent::SetPos(const sf::Vector2f& PosL, const sf::Vector2f& PosR)
{
	posL = PosL;
	posR = PosR;
	left.setPosition(sprite.getPosition() + posL);
	right.setPosition(sprite.getPosition() + posR);
}