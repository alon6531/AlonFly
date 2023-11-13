#include "Level3.h"

Level3::Level3(F15& F15, Map* Map) : Level(F15, Map), f15(F15)
{
	map = new Map3();
	end = false;
	
	f15.AddBomb(0.3, false, 20, 5);
	targets.push_back(new Target("Image/home.png", sf::Vector2f(500, 650), sf::Vector2f(100, 100)));
	targets.push_back(new Target("Image/home.png", sf::Vector2f(300, 650), sf::Vector2f(100, 100)));
	targets.push_back(new Target("Image/home.png", sf::Vector2f(800, 650), sf::Vector2f(100, 100)));
	targets.push_back(new Target("Image/home.png", sf::Vector2f(1000, 650), sf::Vector2f(100, 100)));
	targets2.push_back(new Target("Image/Build.png", sf::Vector2f(310, 700), sf::Vector2f(200, 200)));
	targets2.push_back(new Target("Image/Build.png", sf::Vector2f(650, 700), sf::Vector2f(200, 200)));
	targets2.push_back(new Target("Image/Build.png", sf::Vector2f(1050, 700), sf::Vector2f(200, 200)));
}

void Level3::Update(float dt)
{
	map->Update(dt);
	f15.Update(dt);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		f15.ShootBomb("Image/rokcet.png", f15.Sprite().getPosition(), sf::Vector2f(35, 35), 500, dt);
	}

	for (int i = 0; i < targets.size(); i++) {
		for (int j = 0; j < f15.GetBomb().size(); j++) {
			if (f15.GetBomb()[j]->IsCollide(targets[i]->Sprite().getGlobalBounds()))
			{
				targets[i]->SetTexture("Image/destroyHome.png");
			}
		}
	}

	for (int i = 0; i < targets2.size(); i++) {
		for (int j = 0; j < f15.GetBomb().size(); j++) {
			if (f15.GetBomb()[j]->IsCollide(targets2[i]->Sprite().getGlobalBounds()))
			{
				targets2[i]->SetTexture("Image/destroyBuild.png");
				targets2[i]->Sprite().setScale(1, 1);
			}
		}
	}


	for (int i = 0; i < targets.size(); i++) {
		targets[i]->Update(dt);
	}

	for (int i = 0; i < targets2.size(); i++) {
		targets2[i]->Update(dt);
	}
}

void Level3::Render(sf::RenderWindow& Window)
{
	map->Render(Window);
	f15.Render(Window);

	for (int i = 0; i < targets.size(); i++) {
		targets[i]->Render(Window);
	}

	for (int i = 0; i < targets2.size(); i++) {
		targets2[i]->Render(Window);
	}
}

bool Level3::IsEnd()
{
	return end;
}

void Level3::EndLevel(std::stack<Level*>& levels, std::stack<AnimScene*>* animScene)
{
}
