#include "GameState.h"

GameState::GameState()
{
	animScene.push(new AnimScene1());
	//StartScene();
	
}

void GameState::StartScene()
{
	f15 = new F15(sf::Vector2f(0, 0));
	map = NULL;
	level.push(new Level1(*f15, map));
}


void GameState::Update(float dt, std::stack<State*>& states)
{
	if (animScene.top()) {
		if (!animScene.top()->IsEnd()) {
			animScene.top()->Update(dt);
			return;
		}
	}


	level.top()->Update(dt);

	if (level.top()->IsEnd()) {
		level.top()->EndLevel(level, NULL);
	}

	
}

void GameState::Render(sf::RenderWindow& window)
{
	if (animScene.top()) {
		if (!animScene.top()->IsEnd()) {
			animScene.top()->Render(window);
			return;
		}
		else if (StartGame == false) {
			StartScene();
			StartGame = true;
		}
	}

	level.top()->Render(window);
}



