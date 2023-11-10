#pragma once
#include "State.h"
#include "Button.h"
#include "Text.h"

class MainMenuState :
    public State
{
private:
    Text* title;
    Button* startB;
    bool endState;

public:
    MainMenuState();
    void Update(float dt, std::stack<State*>& states) override;

    void Render(sf::RenderWindow& window) override;

};

