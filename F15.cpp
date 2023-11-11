#include "F15.h"

F15::F15(const sf::Vector2f& Pos) : Entity("Image/F15.png", Pos, sf::Vector2f(50, 50))
{
	AddHitBoxComponent();
	AddMoveComponent(500);
	AddEngineComponent("Image/EnigeFire.png", sf::Vector2f(-75, 10), sf::Vector2f(-75, 0), sf::Vector2f(0.05, 0.05));
	CantExitScreen();

	bulletDelay = new Timer(0.5f);
	bombDelay = new Timer(2.f, 0);
}

void F15::Update(float dt)
{

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		Move(dt, sf::Vector2i(-1, 0));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		Move(dt, sf::Vector2i(1, 0));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		Move(dt, sf::Vector2i(0, -1));

	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		Move(dt, sf::Vector2i(0, 1));

	}



	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && bulletDelay->IsEnd()) {

		sf::Vector2f shootPlaceL = sf::Vector2f(Sprite().getPosition().x, Sprite().getPosition().y + 20);
		sf::Vector2f shootPlaceR = sf::Vector2f(Sprite().getPosition().x, Sprite().getPosition().y - 20);

		leftProj.push_back(new Projectile("Image/bullet.png", shootPlaceL, sf::Vector2f(40, 40), 5000));
		rightProj.push_back(new Projectile("Image/bullet.png", shootPlaceR, sf::Vector2f(40, 40), 5000));

		bulletDelay->Reset();
	}

	for (int i = 0; i < leftProj.size(); i++) {
		leftProj[i]->Update(dt);
	}
	for (int i = 0; i < rightProj.size(); i++) {
		rightProj[i]->Update(dt);
	}
	bulletDelay->Update(dt);




	if (sf::Keyboard::isKeyPressed(sf::Keyboard::E) && bombDelay->IsEnd()) {

		bomb.push_back(new Projectile("Image/rokcet.png", Sprite().getPosition(), sf::Vector2f(40, 40), 1500));

		bombDelay->Reset();
	}

	for (int i = 0; i < bomb.size(); i++) {
		bomb[i]->Update(dt);
	}
	bombDelay->Update(dt);



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

	for (int i = 0; i < bomb.size(); i++) {
		bomb[i]->Render(Window);
	}
	Entity::Render(Window);
}
