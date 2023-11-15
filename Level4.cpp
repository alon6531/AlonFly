#include "Level4.h"

Level4::Level4(F15& F15, Map* Map) : Level(F15, Map), map(Map), f15(F15)
{
	map = new AirportMap();
	end = false;

	f15.Sprite().setPosition(sf::Vector2f(300, 0));
	f15.RemoveBomb();

	target = new Target("Image/blank.png", sf::Vector2f(700, 500), sf::Vector2f(2500, 1000));


	task = new Text("*Land you F15", sf::Vector2f(1100, 20), sf::Vector2f(1, 1), sf::Color::Black);
}

void Level4::Update(float dt)
{

	if (map)
		map->Update(dt);

	if (target)
		target->Update(dt);

	if (target->IsCollide(f15.Sprite().getGlobalBounds())) {
		end = true;
		std::cout << "enter" << "\n";
	}

	f15.Update(dt);
}

void Level4::Render(sf::RenderWindow& Window)
{
	if (map)
		map->Render(Window);

	if (target)
		target->Render(Window);

	f15.Render(Window);

	task->Render(Window);
}

bool Level4::IsEnd()
{
	return end;
}

void Level4::EndLevel(std::stack<Level*>& levels, std::stack<AnimScene*>* animScene)
{
	animScene->push(new AnimScene5());
	bDone = true;
}
