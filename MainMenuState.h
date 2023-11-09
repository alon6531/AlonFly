#pragma once
#include "State.h"
#include "Button.h"

class MainMenuState :
    public State
{
private:
    sf::Text Title;
    Button* startB;
    bool endState;

public:
    MainMenuState();
    void Update(float dt, State& state) override;

    void Render(sf::RenderWindow& window) override;

};

