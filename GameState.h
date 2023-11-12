#pragma once
#include "State.h"
#include "F15.h"
#include "Mig29.h"
#include "Map1.h"
#include "Helicopter.h"
#include "AnimScene1.h"

class GameState :
    public State
{
private:
    sf::Sprite bg;
    sf::Texture texture;
    F15* f15;
    std::vector<Plane*> enemy;
    Map* map;
    AnimScene1* animScene1;
    bool StartGame = false;

public:
    GameState();

    void Update(float dt, std::stack<State*>& states) override;

    void Render(sf::RenderWindow& window) override;

    void StartScene();
};

