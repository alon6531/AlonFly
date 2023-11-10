#pragma once
#include "State.h"
class GameState :
    public State
{
private:


public:
    void Update(float dt, std::stack<State*>& states) override;

    void Render(sf::RenderWindow& window) override;

};

