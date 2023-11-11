#pragma once
#include "State.h"
#include "F15.h"

class GameState :
    public State
{
private:
    sf::Sprite bg;
    sf::Texture texture;
    F15* f15;

public:
    GameState();

    void Update(float dt, std::stack<State*>& states) override;

    void Render(sf::RenderWindow& window) override;

};

