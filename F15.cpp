#include "F15.h"

F15::F15(const sf::Vector2f& Pos) : Entity("Image/F15.png", Pos, sf::Vector2f(50, 50))
{
	AddHitBoxComponent();
	AddMoveComponent(500);

	delay = new Timer(0.5f);
	dir = sf::Vector2i(0, -1);
}

void F15::Update(float dt)
{
	sf::Vector2f shootPlaceL;
	sf::Vector2f shootPlaceR;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		dir = sf::Vector2i(-1, 0);
		Move(dt, sf::Vector2i(-1, 0));

		shootPlaceL = sf::Vector2f(Sprite().getPosition().x, Sprite().getPosition().y + 20);
		shootPlaceR = sf::Vector2f(Sprite().getPosition().x, Sprite().getPosition().y - 20);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		dir = sf::Vector2i(1, 0);
		Move(dt, sf::Vector2i(1, 0));

		shootPlaceL = sf::Vector2f(Sprite().getPosition().x, Sprite().getPosition().y + 20);
		shootPlaceR = sf::Vector2f(Sprite().getPosition().x, Sprite().getPosition().y - 20);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		dir = sf::Vector2i(0, -1);
		Move(dt, sf::Vector2i(0, -1));

		shootPlaceL = sf::Vector2f(Sprite().getPosition().x + 20, Sprite().getPosition().y);
		shootPlaceR = sf::Vector2f(Sprite().getPosition().x - 20, Sprite().getPosition().y);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		dir = sf::Vector2i(0, 1);
		Move(dt, sf::Vector2i(0, 1));

		shootPlaceL = sf::Vector2f(Sprite().getPosition().x + 20, Sprite().getPosition().y);
		shootPlaceR = sf::Vector2f(Sprite().getPosition().x - 20, Sprite().getPosition().y);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && delay->IsEnd()) {
		leftProj.push_back(new Projectile("Image/bullet.png", shootPlaceL, sf::Vector2f(40, 40), dir, 5000));
		rightProj.push_back(new Projectile("Image/bullet.png", shootPlaceR, sf::Vector2f(40, 40), dir, 5000));

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

void F15::Render(sf::RenderWindow& Window)
{
	for (int i = 0; i < leftProj.size(); i++) {
		leftProj[i]->Render(Window);
	}
	for (int i = 0; i < rightProj.size(); i++) {
		rightProj[i]->Render(Window);
	}
	Entity::Render(Window);
}
