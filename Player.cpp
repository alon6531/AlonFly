#include "Player.h"

Player::Player(const std::string& string, const sf::Vector2f& scale) : Entity(string, scale)
{
	AddHitBoxComponent();
	AddMoveComponent(100);

	delay = new Timer(0.5f);
	dir = sf::Vector2i(0, -1);
}

void Player::Update(float dt)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		dir = sf::Vector2i(-1, 0);
		Move(dt, sf::Vector2i(-1, 0));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		dir = sf::Vector2i(1, 0);
		Move(dt, sf::Vector2i(1, 0));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		dir = sf::Vector2i(0, -1);
		Move(dt, sf::Vector2i(0, -1));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		dir = sf::Vector2i(0, 1);
		Move(dt, sf::Vector2i(0, 1));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && delay->IsEnd()) {
		if (dir == sf::Vector2i(1, 0) || dir == sf::Vector2i(-1, 0)) {
			leftProj.push_back(new Projectile("Image/bullet.png", sf::Vector2f(Sprite().getPosition().x, Sprite().getPosition().y + 20), sf::Vector2f(40, 40), dir, 500));
			rightProj.push_back(new Projectile("Image/bullet.png", sf::Vector2f(Sprite().getPosition().x, Sprite().getPosition().y - 20), sf::Vector2f(40, 40), dir, 500));
			
		}
		else {
			leftProj.push_back(new Projectile("Image/bullet.png", sf::Vector2f(Sprite().getPosition().x + 20, Sprite().getPosition().y), sf::Vector2f(40, 40), dir, 500));
			rightProj.push_back(new Projectile("Image/bullet.png", sf::Vector2f(Sprite().getPosition().x - 20, Sprite().getPosition().y), sf::Vector2f(40, 40), dir, 500));
		}
		delay->Reset();
	}
	for (int i = 0; i < leftProj.size(); i++) {
		leftProj[i]->Update(dt);
	}
	for (int i = 0; i < rightProj.size(); i++) {
		rightProj[i]->Update(dt);
	}

	delay->Update(dt);

	Entity::Update(dt);
}

void Player::Render(sf::RenderWindow& Window)
{
	for (int i = 0; i < leftProj.size(); i++) {
		leftProj[i]->Render(Window);
	}
	for (int i = 0; i < rightProj.size(); i++) {
		rightProj[i]->Render(Window);
	}
	Entity::Render(Window);
}
