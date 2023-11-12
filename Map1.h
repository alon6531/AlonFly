#pragma once
#include "Map.h"
class Map1 :
    public Map
{
private:
    sf::Sprite bg;
    sf::Texture bgTexture;
    std::vector<float> speed;
    std::vector<sf::Sprite> cloud;
    sf::Texture texture;


public:
    Map1();

    void Update(float dt) override;


    void Render(sf::RenderWindow& Window) override;
};

