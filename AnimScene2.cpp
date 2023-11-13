#include "AnimScene2.h"

AnimScene2::AnimScene2()
{
	map = new Map1();
	f15Texture.loadFromFile("Image/F15/f15_3.png");
	f15.setTexture(f15Texture);
	f15.setScale(1, 1);
	f15.setPosition(sf::Vector2f(-100, 300));

	mig29Texture.loadFromFile("Image/Mig29.png");
	mig29.setTexture(mig29Texture);
	mig29.setScale(0, 0);
	mig29.setPosition(sf::Vector2f(0, 0));

	f15MoveForword = new Timer(2.5);
	mig29MoveTof15 = new Timer(1.5);
	mig29MoveForword = new Timer(0.5);
	end = false;
}

void AnimScene2::Update(float dt)
{
	if (!f15MoveForword->IsEnd())
		f15.move(dt * 400, 0);
	else
	{
		mig29.setScale(0.3, 0.3);

		if (!mig29MoveTof15->IsEnd())
			mig29.move(dt * 200, dt * 200);
		else
		{
			if (!mig29MoveForword->IsEnd()) {
				mig29.move(dt * 100, 0);
			}
			else
				end = true;

			mig29MoveForword->Update(dt);
		}


		mig29MoveTof15->Update(dt);
	}

	f15MoveForword->Update(dt);

	map->Update(dt);
}

void AnimScene2::Render(sf::RenderWindow& Window)
{
	map->Render(Window);


	Window.draw(f15);
	Window.draw(mig29);
}

bool AnimScene2::IsEnd()
{
	return end;
}
