#include "Mig29.h"

Mig29::Mig29(const sf::Vector2f& Pos) : Plane("Image/Mig29.png", Pos, sf::Vector2f(25, 25))
{
	srand(time(NULL));
	AddHitBoxComponent();
	AddMoveComponent(200);
	//AddEngineComponent("Image/EnigeFire.png", sf::Vector2f(-75, 15), sf::Vector2f(0.05, 0.05));
	CantExitScreen();
	AddBullet(0.5, true);
	AddHealthComponent(10);
	delay = new Timer(0.5);
}

void Mig29::Update(float dt, sf::Sprite* TargetSprite)
{


	
	if (TargetSprite->getPosition().x > Sprite().getPosition().x)
	{
		if (Sprite().getPosition().y > TargetSprite->getPosition().y) {
			Move(dt, sf::Vector2i(0, -1));
		}
		if (Sprite().getPosition().y < TargetSprite->getPosition().y) {
			Move(dt, sf::Vector2i(0, 1));
		}

		ShootBullet("Image/bullet.png",
			sf::Vector2f(Sprite().getPosition().x, Sprite().getPosition().y + 20), sf::Vector2f(40, 40), 1250);
	}
	else {
		std::cout << delay->CurrentTime() << " " << rand << "\n";
		if (delay->IsEnd())
		{
			rand = std::rand() % 2 + 1;
			delay->Reset();
		}
		if (rand == 1) {
			Move(dt, sf::Vector2i(0, -1));
		}
		if (rand == 2) {
			Move(dt, sf::Vector2i(0, 1));
		}


	}
	delay->Update(dt);

	Plane::Update(dt);
}

void Mig29::Render(sf::RenderWindow& Window)
{



	Plane::Render(Window);
}


