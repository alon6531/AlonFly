#include "Explotion.h"

Explotion::Explotion(const sf::Vector2f& PosS, const sf::Vector2f& Scale)
{
	textrue.loadFromFile("Image/Explotion/regularExplosion08.png");
	sprite.setTexture(textrue);
	sprite.setPosition(PosS);
	sprite.setScale(Scale);

	timer = new Timer(0.5);
}

void Explotion::Update(float dt)
{
	if (timer->CurrentTime() >= timer->MaxTime() * 0.05 * 9)
	{
		textrue.loadFromFile("Image/Explotion/regularExplosion01.png");
	}
	else if (timer->CurrentTime() >= timer->MaxTime() * 0.05 * 8)
	{
		textrue.loadFromFile("Image/Explotion/regularExplosion01.png");
	}
	else if (timer->CurrentTime() >= timer->MaxTime() * 0.05 * 7)
	{
		textrue.loadFromFile("Image/Explotion/regularExplosion02.png");
	}
	else if (timer->CurrentTime() >= timer->MaxTime() * 0.05 * 6)
	{
		textrue.loadFromFile("Image/Explotion/regularExplosion03.png");
	}
	else if (timer->CurrentTime() >= timer->MaxTime() * 0.05 * 5)
	{
		textrue.loadFromFile("Image/Explotion/regularExplosion04.png");
	}
	else if (timer->CurrentTime() >= timer->MaxTime() * 0.05 * 4)
	{
		textrue.loadFromFile("Image/Explotion/regularExplosion05.png");
	}
	else if (timer->CurrentTime() >= timer->MaxTime() * 0.05 * 3)
	{
		textrue.loadFromFile("Image/Explotion/regularExplosion06.png");
	}
	else if (timer->CurrentTime() >= timer->MaxTime() * 0.05 * 2)
	{
		textrue.loadFromFile("Image/Explotion/regularExplosion07.png");
	}
	else if (timer->CurrentTime() >= timer->MaxTime() * 0.05 * 1)
	{
		textrue.loadFromFile("Image/Explotion/regularExplosion08.png");
	}

	timer->Update(dt);
	sprite.setTexture(textrue);
}

void Explotion::Render(sf::RenderWindow& Window)
{
	Window.draw(sprite);
}

bool Explotion::IsEnd()
{
	return timer->IsEnd();
}
