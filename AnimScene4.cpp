#include "AnimScene4.h"

AnimScene4::AnimScene4()
{
	map = new Map3();
	f15Texture.loadFromFile("Image/F15/f15_3.png");
	f15.setTexture(f15Texture);
	f15.setScale(1, 1);
	f15.setPosition(sf::Vector2f(500, 300));
	end = false;
	initLevel = true;
	f15MoveForword = new Timer(2.5);
	f15MoveForword2 = new Timer(0.5);
	targets.push_back(new Target("Image/destroyHome.png", sf::Vector2f(500, 650), sf::Vector2f(100, 100)));
	targets.push_back(new Target("Image/destroyHome.png", sf::Vector2f(300, 650), sf::Vector2f(100, 100)));
	targets.push_back(new Target("Image/destroyHome.png", sf::Vector2f(800, 650), sf::Vector2f(100, 100)));
	targets.push_back(new Target("Image/destroyHome.png", sf::Vector2f(1000, 650), sf::Vector2f(100, 100)));
	targets.push_back(new Target("Image/destroyBuild.png", sf::Vector2f(310, 700), sf::Vector2f(50, 50)));
	targets.push_back(new Target("Image/destroyBuild.png", sf::Vector2f(650, 700), sf::Vector2f(50, 50)));
	targets.push_back(new Target("Image/destroyBuild.png", sf::Vector2f(1050, 700), sf::Vector2f(50, 50)));
}

void AnimScene4::Update(float dt)
{
	if (f15MoveForword->IsEnd())
	{

		if (f15MoveForword2->IsEnd())
		{
			end = true;
		}
		f15.move(dt * 400, 0);

		f15MoveForword2->Update(dt);

		if (f15MoveForword->IsEnd() && initLevel) {
			map = new AirportMap();
			initLevel = false;
			f15.setPosition(sf::Vector2f(-100, 0));
		}

	}
	else
	{
		f15.move(dt * 400, 0);

		if (map)
			map->Update(dt);


		f15MoveForword->Update(dt);
	}

}

void AnimScene4::Render(sf::RenderWindow& Window)
{


	if (map)
		map->Render(Window);

	if (!f15MoveForword->IsEnd())
	{
		for (int i = 0; i < targets.size(); i++) {
			targets[i]->Render(Window);
		}
	}

	Window.draw(f15);
}

bool AnimScene4::IsEnd()
{
	return end;
}
