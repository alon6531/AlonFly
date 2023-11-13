#include "GameState.h"

GameState::GameState()
{
	//StartAnimScene();
	StartScene();
	
}

void GameState::StartAnimScene()
{
	animScene = new std::stack<AnimScene*>();
	animScene->push(new AnimScene1());
}

void GameState::StartScene()
{
	f15 = new F15(sf::Vector2f(0, 0));
	map = NULL;
	level.push(new Level3(*f15, map));
}


void GameState::Update(float dt, std::stack<State*>& states)
{
	if (animScene) {
		if (animScene->top()) {
			if (!animScene->top()->IsEnd()) {
				animScene->top()->Update(dt);
				return;
			}
		}
	}
	level.top()->Update(dt);

	if (level.top()->IsEnd()) {
		level.top()->EndLevel(level, animScene);
	}

	if (f15->GetHealth() <= 0)
		states.push(new MainMenuState());
}

void GameState::Render(sf::RenderWindow& window)
{
	if (animScene) {
		if (animScene->top()) {
			if (!animScene->top()->IsEnd()) {
				animScene->top()->Render(window);
				return;
			}
			else if (StartGame == false) {
				StartScene();
				StartGame = true;
			}
		}
	}

	level.top()->Render(window);
}



