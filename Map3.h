#pragma once
#include "Map.h"
class Map3 :
    public Map
{
private:
    sf::Sprite house;
    sf::Sprite house1;
    sf::Sprite house2;
    sf::Texture text;
    sf::Sprite bg;
    sf::Texture bgTexture;

    std::vector<float> speed;
    std::vector<sf::Sprite> cloud;
    sf::Texture texture;


public:
    Map3();

    void Update(float dt) override;

    void Render(sf::RenderWindow& Window) override;
};

