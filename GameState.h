#pragma once
#include "State.h"
#include "F15.h"
#include "Level1.h"

class GameState :
    public State
{
private:
 
    F15* f15;
    AnimScene1* animScen1;
    Map* map;
    bool StartGame = false;
    std::stack<Level*> level;
    std::stack<AnimScene*> animScene;

public:
    GameState();

    void Update(float dt, std::stack<State*>& states) override;

    void Render(sf::RenderWindow& window) override;

    void StartScene();
};

