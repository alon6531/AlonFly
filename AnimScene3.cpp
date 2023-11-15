#include "AnimScene3.h"

AnimScene3::AnimScene3()
{
	map = new Map1();
	f15Texture.loadFromFile("Image/F15/f15_3.png");
	f15.setTexture(f15Texture);
	f15.setScale(1, 1);
	f15.setPosition(sf::Vector2f(200, 200));
	end = false;
	f15MoveDown = new Timer(4);
	f15.setRotation(20);
	speed = 350;
}

void AnimScene3::Update(float dt)
{
	f15.move(400 * dt, 200 * dt);


	if (f15MoveDown->IsEnd()) {
		end = true;
	}
	map->Update(dt);

	f15MoveDown->Update(dt);
}

void AnimScene3::Render(sf::RenderWindow& Window)
{
	map->Render(Window);

	Window.draw(f15);
}

bool AnimScene3::IsEnd()
{
	return end;
}
