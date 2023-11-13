#include "Target.h"

Target::Target(const std::string& String, const sf::Vector2f& Pos, const sf::Vector2f& Scale) : Entity(String, Pos, Scale)
{
	AddHitBoxComponent();
}




