#pragma once
#include "Entity.h"
class Player :
    public Entity
{
private:

public:
    Player(const std::string& string);

    void Update(float dt);
};

