#include "GameState.h"

GameState::GameState()
{
	animScene1 = new AnimScene1();
	//StartScene();
	
}

void GameState::StartScene()
{
	map = new Map1();
	f15 = new F15(sf::Vector2f(800, 100));

	texture.loadFromFile("Image/Sky.png");
	bg.setTexture(texture);
	bg.setScale(sf::Vector2f(2.2, 2));

	//enemy.push_back(new Mig29(sf::Vector2f(500, 50)));
	//enemy.push_back(new Mig29(sf::Vector2f(500, 50)));
	enemy.push_back(new Mig29(sf::Vector2f(600, 300)));
}


void GameState::Update(float dt, std::stack<State*>& states)
{
	if (animScene1) {
		if (!animScene1->IsEnd()) {
			animScene1->Update(dt);
			return;
		}
	}
	
	map->Update(dt);

	f15->Update(dt);

	for (int i = 0; i < enemy.size(); i++) {

		enemy[i]->Update(dt, &f15->Sprite());

		//mig hit f15
		for (int j = 0; j < enemy[i]->GetBullet().size(); j++) {
			if (f15->IsCollide(enemy[i]->GetBullet()[j]->rect())) {
				f15->OnHit(1);
				enemy[i]->DeleteBullet(j);
				std::cout << f15->GetHealth() << "\n";
			}
		}
		
		//bullet of f15 hit mig
		for (int j = 0; j < f15->GetBullet().size(); j++)
		{
			if (enemy.at(i)->IsCollide(f15->GetBullet()[j]->rect())) {
				enemy[i]->OnHit(1);
				f15->DeleteBullet(j);
			}

		}

		//bomb of f15 hit mig
		for (int j = 0; j < f15->GetBomb().size(); j++)
		{
			if (enemy.at(i)->IsCollide(f15->GetBomb()[j]->rect())) {
				enemy[i]->OnHit(10);
				f15->DeleteBomb(j);
			}

		}
		
		if (enemy[i]->GetHealth() <= 0)
			enemy.erase(enemy.begin() + i);

		
		
	}

}

void GameState::Render(sf::RenderWindow& window)
{
	if (animScene1) {
		if (!animScene1->IsEnd()) {
			animScene1->Render(window);
			return;
		}
		else if (StartGame == false) {
			StartScene();
			StartGame = true;
		}
	}

	map->Render(window);

	f15->Render(window);

	for (int i = 0; i < enemy.size(); i++) {
		enemy[i]->Render(window);
	}
}



