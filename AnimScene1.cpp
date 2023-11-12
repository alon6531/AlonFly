#include "AnimScene1.h"


AnimScene1::AnimScene1()
{
	texture.loadFromFile("Image/F15/f15Land1.png");
	sprite.setTexture(texture);
	sprite.setScale(1, 1);
	sprite.setPosition(sf::Vector2f(0, 650));

	moveForword = true;
	map = new AirportMap();
	end = false;
	takeOf = new Timer(6);

	boeingTexture.loadFromFile("Image/Boeing.png");
	boeing.setTexture(boeingTexture);
	boeing.setScale(0.5, 0.5);
	boeing.setPosition(1200, 20);
}

void AnimScene1::Update(float dt)
{
	if (moveForword) {
		if (sprite.getPosition().x < 500)
			sprite.move(dt * 300, 0);
		else
		{
			moveForword = false;
			takeOf->Reset();
			texture.loadFromFile("Image/F15/f15Land2.png");
			sprite.setTexture(texture);
		}
	}
	else {
		if (!takeOf->IsEnd()) {
			std::cout << sprite.getRotation() << "\n";
			if (sprite.getRotation() > 340 || sprite.getRotation() == 0)
				sprite.rotate(-0.02);

			sprite.move(dt * 200, -2 * dt * 100);

		}
		else
		{
			end = true;
		}
	}

	takeOf->Update(dt);
	
	boeing.move(-dt * 200, 0);

}

void AnimScene1::Render(sf::RenderWindow& Window)
{
	map->Render(Window);

	Window.draw(boeing);

	Window.draw(sprite);


}

bool AnimScene1::IsEnd()
{
	return end;
}
