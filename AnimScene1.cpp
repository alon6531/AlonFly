#include "AnimScene1.h"


AnimScene1::AnimScene1()
{
	f15Texture.loadFromFile("Image/F15/f15Land1.png");
	f15.setTexture(f15Texture);
	f15.setScale(1, 1);
	f15.setPosition(sf::Vector2f(0, 650));

	moveForword = true;
	map = new AirportMap();
	end = false;
	takeOf = new Timer(6);

	boeingTexture.loadFromFile("Image/Boeing.png");
	boeing.setTexture(boeingTexture);
	boeing.setScale(0.5, 0.5);
	boeing.setPosition(1200, 20);



	buffer.loadFromFile("Sound/TakeOF.wav");
	sound.setVolume(100);
	sound.setBuffer(buffer);
	sound.play();
}

void AnimScene1::Update(float dt)
{
	
	
	if (moveForword) {
		if (f15.getPosition().x < 500)
			f15.move(dt * 300, 0);
		else
		{
			moveForword = false;
			takeOf->Reset();
			f15Texture.loadFromFile("Image/F15/f15Land2.png");
			f15.setTexture(f15Texture);
		}
	}
	else {
		if (!takeOf->IsEnd()) {
			if (f15.getRotation() > 340 || f15.getRotation() == 0)
				f15.rotate(-0.02);

			f15.move(dt * 200, -2 * dt * 100);

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

	Window.draw(f15);


}

bool AnimScene1::IsEnd()
{
	return end;
}
