#pragma once
#include "State.h"
class GameState :
    public State
{
private:


public:
    void Update(float dt, State& state) override;

    void Render(sf::RenderWindow& window) override;

};

