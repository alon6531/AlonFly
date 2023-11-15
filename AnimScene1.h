#pragma once
#include "AnimScene.h"
#include "AirportMap.h"


class AnimScene1 :
    public AnimScene
{
private:
    sf::Sprite f15;
    sf::Texture f15Texture;
    bool moveForword;
    sf::Sprite boeing;
    sf::Texture boeingTexture;
    Map* map;
    bool end;
    Timer* takeOf;

    sf::Sound sound;
    sf::SoundBuffer buffer;
public:
    AnimScene1();

    void Update(float dt) override;
    void Render(sf::RenderWindow& Window) override;

    bool IsEnd() override;
};

