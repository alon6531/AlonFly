#include "Entity.h"

Entity::Entity(const std::string& string, const sf::Vector2f& scale)
{
	if (!texture.loadFromFile(string))
		std::cout << "CANT_LOAD_TEXTURE \n";
	sprite.setTexture(texture);


	sprite.setOrigin(sprite.getGlobalBounds().width / 2, sprite.getGlobalBounds().height / 2);
	sprite.setScale(sf::Vector2f(scale.x / 100, scale.y / 100));

	moveComponent = NULL;
	hitBoxComponent = NULL;
}

Entity::Entity(const std::string& string, const sf::Vector2f& Pos, const sf::Vector2f& Scale)
{
	if (!texture.loadFromFile(string))
		std::cout << "CANT_LOAD_TEXTURE \n";
	sprite.setTexture(texture);

	sprite.setPosition(Pos);
	sprite.setOrigin(sprite.getGlobalBounds().width / 2, sprite.getGlobalBounds().height / 2);
	sprite.setScale(sf::Vector2f(Scale.x / 100, Scale.y / 100));

	moveComponent = NULL;
	hitBoxComponent = NULL;
}

sf::Sprite& Entity::Sprite()
{
	return sprite;
}

void Entity::AddMoveComponent(float MoveSpeed)
{
	moveComponent = new MoveComponent(sprite, MoveSpeed);
}

void Entity::AddHitBoxComponent()
{
	hitBoxComponent = new HitBoxComponent(sprite);
}

void Entity::AddEngineComponent(const std::string& string, const sf::Vector2f& PosL, const sf::Vector2f& PosR, const sf::Vector2f& Scale)
{
	engineComponent = new EngineComponent(sprite, string, PosL, PosR, Scale);
}

bool Entity::IsCollide(const sf::FloatRect& Rect)
{
	return hitBoxComponent->IsCollide(Rect);
}

void Entity::Update(float dt)
{
	if (hitBoxComponent) {
		hitBoxComponent->Update();
	}

	if (engineComponent) {
		engineComponent->Update(dt);
	}

}

void Entity::Render(sf::RenderWindow& window)
{
	window.draw(sprite);

	if (hitBoxComponent) {
		hitBoxComponent->Render(window);
	}

	if (engineComponent) {
		engineComponent->Render(window);
	}
}

void Entity::Move(float dt, const sf::Vector2i& Dir)
{
	if (moveComponent) {
		if (Dir == sf::Vector2i(-1, 0)) {
			moveComponent->MoveLeft(dt);
		}
		if (Dir == sf::Vector2i(1, 0)) {
			moveComponent->MoveRight(dt);
			if (engineComponent) {
				engineComponent->StartEngine();
			}
		}
		if (Dir == sf::Vector2i(0, -1)) {
			moveComponent->MoveUp(dt);
		}
		if (Dir == sf::Vector2i(0, 1)) {
			moveComponent->MoveDown(dt);
		}
		

	}

}

void Entity::CantExitScreen()
{
	if (hitBoxComponent) {
		hitBoxComponent->SetCantExitScreen();
	}
}



