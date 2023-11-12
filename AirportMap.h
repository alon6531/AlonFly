#pragma once
#include "Map.h"
class AirportMap :
    public Map
{
private:
    sf::Sprite bg;
    sf::Texture bgTexture;


public:
    AirportMap();

    void Update(float dt) override;

    void Render(sf::RenderWindow& Window) override;

};

