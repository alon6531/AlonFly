#include "Plane.h"

Plane::Plane(const std::string& string, const sf::Vector2f& Pos, const sf::Vector2f& Scale) : Entity(string, Pos, Scale)
{
	bullet = NULL;
	bulletDelay = NULL;
	Rocket = NULL;
	RocketDelay = NULL;

}

void Plane::Update(float dt, sf::Sprite* TargetSprite)
{
	if (bullet) {
		for (int i = 0; i < bullet->size(); i++) {
			bullet->at(i)->Update(dt, shootBulletL_R);

			if (bullet->at(i)->IsDead())
				DeleteBullet(i);
		}
		bulletDelay->Update(dt);
	}

	if (Rocket) {
		for (int i = 0; i < Rocket->size(); i++) {
			Rocket->at(i)->Update(dt, shootBulletL_R);

			if (Rocket->at(i)->IsDead())
				DeleteRocket(i);
		}
		RocketDelay->Update(dt);
	}

	if (bomb) {
		for (int i = 0; i < bomb->size(); i++) {
			bomb->at(i)->Update(dt, shootBombL_R);

			if (bomb->at(i)->IsDead())
				DeleteBomb(i);
		}
		BombDelay->Update(dt);
	}

	if(bulletReloadSystem)
		bulletReloadSystem->Update(dt);

	if (RocketReloadSystem)
		RocketReloadSystem->Update(dt);

	if (BombReloadSystem)
		BombReloadSystem->Update(dt);

	for (int i = 0; i < explotion.size(); i++) {
		explotion[i]->Update(dt);
		if (explotion[i]->IsEnd())
			explotion.erase(explotion.begin() + i);
	}

	Entity::Update(dt);
}

void Plane::Render(sf::RenderWindow& Window)
{
	if (bullet) {
		for (int i = 0; i < bullet->size(); i++) {
			bullet->at(i)->Render(Window);
		
		}
		
	}

	if (Rocket) {
		for (int i = 0; i < Rocket->size(); i++) {
			Rocket->at(i)->Render(Window);

			if (Rocket->at(i)->IsDead())
				Rocket->erase(Rocket->begin() + i);
		}
	}

	if (bomb) {
		for (int i = 0; i < bomb->size(); i++) {
			bomb->at(i)->Render(Window);

			if (bomb->at(i)->IsDead())
				bomb->erase(bomb->begin() + i);
		}
	}

	if (bulletReloadSystem)
		bulletReloadSystem->Render(Window);

	if (RocketReloadSystem)
		RocketReloadSystem->Render(Window);

	if (BombReloadSystem)
		BombReloadSystem->Render(Window);

	for (int i = 0; i < explotion.size(); i++) {
		explotion[i]->Render(Window);
	}

	Entity::Render(Window);
}

void Plane::AddBullet(float FireRate, bool L_R, int Magazine, float ReloadTIme, float StartRate)
{
	bulletReloadSystem = new ReloadSystem(Magazine, ReloadTIme, sf::Vector2f(50, 650));
	bullet = new std::vector<Projectile*>();
	shootBulletL_R = L_R;
	bulletDelay = new Timer(FireRate, StartRate);
	
}

void Plane::RemoveBullet()
{
	if (bullet)
		bullet = NULL;
}

void Plane::AddRocket(float FireRate, bool L_R, int Magazine, float ReloadTIme, float StartRate)
{
	RocketReloadSystem = new ReloadSystem(Magazine, ReloadTIme, sf::Vector2f(150, 650));
	Rocket = new std::vector<Projectile*>();
	shootRocketL_R = L_R;
	RocketDelay = new Timer(FireRate, StartRate);
}

void Plane::RemoveRokcet()
{
	if (Rocket)
		Rocket = NULL;
}

void Plane::AddBomb(float FireRate, bool L_R, int Magazine, float ReloadTIme, float StartRate)
{
	BombReloadSystem = new ReloadSystem(Magazine, ReloadTIme, sf::Vector2f(250, 650));
	bomb = new std::vector<Projectile*>();
	shootBombL_R = L_R;
	BombDelay = new Timer(FireRate, StartRate);
}

void Plane::RemoveBomb()
{
	if (bomb)
		bomb = NULL;
}

void Plane::ShootBullet(const std::string& string, const sf::Vector2f& Pos, const sf::Vector2f& Scale, float Speed, float dt)
{
	if (bullet)
	{
		if (bulletDelay->IsEnd()) {
			if (bulletReloadSystem->IsCanShoot()) {
				bullet->push_back(new Projectile(string, Pos, Scale, Speed));
				bulletDelay->Reset();
				bulletSound.push_back(new sf::Music());
				bulletSound.at(bulletSound.size() - 1)->openFromFile("Sound/bullet.wav");
				bulletSound.at(bulletSound.size() - 1)->play();
				bulletReloadSystem->Shoot();
			}

		}
	}
}

void Plane::ShootRocket(const std::string& string, const sf::Vector2f& Pos, const sf::Vector2f& Scale, float Speed)
{
	if (RocketDelay->IsEnd()) {
		if (RocketReloadSystem->IsCanShoot())
		{
			Rocket->push_back(new Projectile(string, Pos, Scale, Speed));
			RocketDelay->Reset();
			rocketSound.push_back(new sf::Music());
			rocketSound.at(rocketSound.size() - 1)->openFromFile("Sound/rocket.wav");
			rocketSound.at(rocketSound.size() - 1)->play();
			RocketReloadSystem->Shoot();
		}
	}
}

void Plane::ShootBomb(const std::string& string, const sf::Vector2f& Pos, const sf::Vector2f& Scale, float Speed, float dt)
{
	if (BombDelay->IsEnd()) {
		if (BombReloadSystem->IsCanShoot())
		{
			bomb->push_back(new Bomb(string, Pos, Scale, Speed));
			BombDelay->Reset();
			bombSound.push_back(new sf::Music());
			bombSound.at(bombSound.size() - 1)->openFromFile("Sound/bomb.wav");
			bombSound.at(bombSound.size() - 1)->play();
			BombReloadSystem->Shoot();
		}
	}
}

std::vector<Projectile*>& Plane::GetBullet()
{
	return *bullet;
}

std::vector<Projectile*>& Plane::GetRocket()
{
	return *Rocket;
}

std::vector<Projectile*>& Plane::GetBomb()
{
	return *bomb;
}

void Plane::DeleteBullet(int i)
{
	if (bullet) {
		if (bullet->at(i)) {
			bullet->erase(bullet->begin() + i);
		}
	}
}

void Plane::DeleteRocket(int i)
{
	if (Rocket) {
		if (Rocket->at(i)) {
			Rocket->erase(Rocket->begin() + i);
		}
	}
}

void Plane::DeleteBomb(int i)
{
	if (bomb) {
		if (bomb->at(i)) {
			bomb->erase(bomb->begin() + i);
		}
	}
}

void Plane::AddExplotion(const sf::Vector2f& PosS, const sf::Vector2f& Scale)
{
	explotion.push_back(new Explotion(PosS, Scale));
}
