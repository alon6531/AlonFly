#include "Level2.h"


Level2::Level2(F15& F15, Map* Map) : Level(F15, Map), f15(F15), map(Map)
{
	map = new Map1();

	enemy.push_back(new Mig29(sf::Vector2f(500, 300)));

	end = false;

	F15.Sprite().setPosition(sf::Vector2f(900, 300));


	task = new Text("*there is a Mig attacking you!* ", sf::Vector2f(900, 20), sf::Vector2f(1, 1), sf::Color::Red);
}

void Level2::Update(float dt)
{


	map->Update(dt);

	f15.Update(dt);

	for (int i = 0; i < enemy.size(); i++) {

		enemy[i]->Update(dt, &f15.Sprite());

		//mig hit f15
		for (int j = 0; j < enemy[i]->GetBullet().size(); j++) {
			if (f15.IsCollide(enemy[i]->GetBullet()[j]->rect())) {
				int damage = rand() % 3 + 1;
				f15.OnHit(damage);
				enemy[i]->DeleteBullet(j);
				std::cout << f15.GetHealth() << "\n";
			}
		}

		//bullet of f15 hit mig
		for (int j = 0; j < f15.GetBullet().size(); j++)
		{
			if (enemy.at(i)->IsCollide(f15.GetBullet()[j]->rect())) {
				enemy[i]->OnHit(1);
				f15.DeleteBullet(j);
			}

		}

		//bomb of f15 hit mig
		for (int j = 0; j < f15.GetRocket().size(); j++)
		{
			if (enemy.at(i)->IsCollide(f15.GetRocket()[j]->rect())) {
				enemy[i]->OnHit(10);
				f15.DeleteRocket(j);
			}

		}

		if (enemy[i]->GetHealth() <= 0)
			enemy.erase(enemy.begin() + i);


	}
	if (enemy.size() == 0) {
		end = true;
	}
}

void Level2::Render(sf::RenderWindow& Window)
{
	map->Render(Window);

	f15.Render(Window);

	for (int i = 0; i < enemy.size(); i++) {
		enemy[i]->Render(Window);
	}

	task->Render(Window);
}

bool Level2::IsEnd()
{
	return end;
}

void Level2::EndLevel(std::stack<Level*>& levels, std::stack<AnimScene*>* animScene)
{
	
	animScene->push(new AnimScene3());
	levels.push(new Level3(f15, map));
}
