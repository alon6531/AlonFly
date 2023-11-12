#include "Map1.h"

Map1::Map1()
{
	srand(time(NULL));

	bgTexture.loadFromFile("Image/Bg.png");
	bg.setTexture(bgTexture);
	bg.setScale(5, 5);

	texture.loadFromFile("Image/Cloud.png");

	

	for (int i = 0; i < 15; i++)
	{
		speed.push_back(250 + (std::rand() % (400 - 250 + 1)));

		int x = 1 + (std::rand() % (2000 - 1 + 1));
		int y = 1 + (std::rand() % (700 - 1 + 1));
		cloud.push_back(sf::Sprite());
		cloud[i].setTexture(texture);
		cloud[i].setPosition(sf::Vector2f(x, y));
	}
}


void Map1::Update(float dt)
{
	
	for (int i = 0; i < cloud.size(); i++)
	{
		

		cloud[i].move(-dt * speed[i], 0);
		
		if (cloud[i].getPosition().x + cloud[i].getGlobalBounds().width  < 0) {
			cloud[i].setPosition(sf::Vector2f(1480 + cloud[i].getGlobalBounds().width, cloud[i].getPosition().y));
		}
	}
	
}

void Map1::Render(sf::RenderWindow & Window)
{
	Window.draw(bg);
	
	for (int i = 0; i < cloud.size(); i++)
	{
		Window.draw(cloud[i]);
	}

}
