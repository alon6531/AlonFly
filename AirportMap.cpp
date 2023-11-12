#include "AirportMap.h"

AirportMap::AirportMap()
{
	bgTexture.loadFromFile("Image/Airport.png");
	bg.setTexture(bgTexture);
}

void AirportMap::Update(float dt)
{

}

void AirportMap::Render(sf::RenderWindow& Window)
{
	Window.draw(bg);
}
