#include "F15.h"

F15::F15(const sf::Vector2f& Pos) : Plane("Image/F15/f15_1.png", Pos, sf::Vector2f(80, 100))
{
	AddHitBoxComponent();
	AddMoveComponent(300);
	CantExitScreen();
	AddBullet(0.5f, true, 10, 3);
	AddRocket(0.1f, true, 1, 5);
	AddHealthComponent(25);

}

void F15::Update(float dt)
{
	SetTexture("Image/F15/f15_2.png");
	Move(dt, sf::Vector2i(-1, 0));
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		SetSpeed(400);
		Move(dt, sf::Vector2i(-1, 0));
		SetSpeed(300);
		SetTexture("Image/F15/f15_1.png");
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		SetSpeed(700);
		Move(dt, sf::Vector2i(1, 0));
		SetSpeed(300);
		SetTexture("Image/F15/f15_3.png");
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		Move(dt, sf::Vector2i(0, -1));

	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		Move(dt, sf::Vector2i(0, 1));

	}



	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
		ShootBullet("Image/bullet.png",
			sf::Vector2f(Sprite().getPosition().x, Sprite().getPosition().y + 20), sf::Vector2f(40, 40), 1250);
	}


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)){
		ShootRocket("Image/rokcet.png", Sprite().getPosition() + sf::Vector2f(0, 20), sf::Vector2f(20, 20), 1500);
	}

	Plane::Update(dt);
}


void F15::Render(sf::RenderWindow& Window)
{

	
	Plane::Render(Window);
}
