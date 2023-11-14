#pragma once
#include "State.h"
#include "F15.h"
#include "Level1.h"
#include "Level2.h"
#include "Level4.h"
#include "MainMenuState.h"

class GameState :
    public State
{
private:
 
    F15* f15;
    AnimScene1* animScen1;
    Map* map;
    bool StartGame = false;
    std::stack<Level*> level;
    std::stack<AnimScene*>* animScene;

    void StartAnimScene();
    void StartScene();
public:
    GameState();

    void Update(float dt, std::stack<State*>& states) override;

    void Render(sf::RenderWindow& window) override;

};

