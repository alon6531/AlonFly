#pragma once
#include "State.h"
#include "Button.h"
#include "Text.h"
#include "GameState.h"
#include "Map1.h"
#include "MainMenuState.h"

class DieScreenState :
    public State
{
private:
    Text* title;
    Button* playAgain;
    bool endState;
    Map* map;

public:
    DieScreenState();
    void Update(float dt, std::stack<State*>& states) override;

    void Render(sf::RenderWindow& window) override;
};

