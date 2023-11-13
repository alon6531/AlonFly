#include "ReloadSystem.h"

ReloadSystem::ReloadSystem(int MaxMagazine, float ReloadTime, const sf::Vector2f& Pos)
{
	maxMagazine = MaxMagazine;
	text = new Text("", Pos, sf::Vector2f(1.5, 1.5), sf::Color::Black);
	reloadTime = new Timer(ReloadTime);
	magazine = maxMagazine;
}

void ReloadSystem::Update(float dt)
{
	if (maxMagazine != -1)
	{
		if (magazine <= 0)
		{
			if (reloadTime->IsEnd())
			{
				magazine = maxMagazine;
				reloadTime->Reset();
			}
			reloadTime->Update(dt);
		}

		text->setString(std::to_string(magazine) + "/" + std::to_string(maxMagazine));
	}
}

void ReloadSystem::Shoot()
{
	if (maxMagazine != -1)
	{
		magazine--;
	}
}

bool ReloadSystem::IsCanShoot()
{
	if (maxMagazine != -1)
	{
		if (magazine > 0)
			return true;
		return false;
	}
	return true;
}

void ReloadSystem::Render(sf::RenderWindow& Window)
{
	if (maxMagazine != -1)
	{
		text->Render(Window);
	}
}
