#pragma once
#include "State.h"
#include "Entity.h"

class GameState :
    public State
{
private:
    Entity* player;

public:
    GameState();

    void Update(float dt, std::stack<State*>& states) override;

    void Render(sf::RenderWindow& window) override;

};

