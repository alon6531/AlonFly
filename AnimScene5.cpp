#include "AnimScene5.h"

AnimScene5::AnimScene5()
{
	map = new AirportMap();
	f15Texture.loadFromFile("Image/F15/f15Land1.png");
	f15.setTexture(f15Texture);
	f15.setScale(1, 1);
	f15.setPosition(sf::Vector2f(50, 200));
	end = false;
	f15Land = new Timer(6);
	f15.setRotation(-5);
	speed = 350;
}

void AnimScene5::Update(float dt)
{
	if(f15.getPosition().y < 650)
		f15.move(dt * 200, dt * 200);
	else
	{
		f15.move(dt * speed, 0);
		if (speed >= 0)
			speed -= dt * 150;
		else
			speed = 0;
	}



	if (f15Land->IsEnd()) {
		end = true;
	}
	map->Update(dt);

	f15Land->Update(dt);
}

void AnimScene5::Render(sf::RenderWindow& Window)
{
	map->Render(Window);

	Window.draw(f15);
}

bool AnimScene5::IsEnd()
{
	return end;
}
