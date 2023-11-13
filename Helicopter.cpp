#include "Helicopter.h"

Helicopter::Helicopter(const sf::Vector2f& Pos) : Plane("Image/Helicopter/1.png", Pos, sf::Vector2f(25, 25))
{
	AddHitBoxComponent();
	AddMoveComponent(100);
	CantExitScreen();
	AddBullet(0.5f, false);
	//AddBomb(1, true, 0);
	AddHealthComponent(25);
	//Sprite().setRotation(-10);

	animDelay = new Timer(0.3);
	StartPos = Pos;

	up_Down = false;
}

void Helicopter::Update(float dt, sf::Sprite* TargetSprite)
{

	if (animDelay->CurrentTime() <= 0.25 * animDelay->MaxTime()) {
		SetTexture("Image/Helicopter/1.png");
	}
	else if(animDelay->CurrentTime() <= 0.50 * animDelay->MaxTime()) {
		SetTexture("Image/Helicopter/2.png");
	}
	else if (animDelay->CurrentTime() <= 0.75 * animDelay->MaxTime()) {
		SetTexture("Image/Helicopter/3.png");
	}
	if (animDelay->IsEnd()) {
		SetTexture("Image/Helicopter/4.png");
		animDelay->Reset();
	}



	float Movement = 50;
	if (up_Down)
	{
		if (Sprite().getPosition().y < StartPos.y + Movement)
		{
			Move(dt, sf::Vector2i(0, 1));
		}
		if (Sprite().getPosition().y >= StartPos.y + Movement) {
			up_Down = false;
		}
	}
	else 
	{
		if (Sprite().getPosition().y > StartPos.y - Movement)
			Move(dt, sf::Vector2i(0, -1));
		if(Sprite().getPosition().y <= StartPos.y - Movement)
			up_Down = true;
	}



	ShootBullet("Image/bullet.png",
		sf::Vector2f(Sprite().getPosition().x, Sprite().getPosition().y + 20), sf::Vector2f(40, 40), 1250);


	animDelay->Update(dt);

	Plane::Update(dt, TargetSprite);
}

void Helicopter::Render(sf::RenderWindow& Window)
{

	Plane::Render(Window);
}
