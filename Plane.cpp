#include "Plane.h"

Plane::Plane(const std::string& string, const sf::Vector2f& Pos, const sf::Vector2f& Scale) : Entity(string, Pos, Scale)
{
	bullet = NULL;
	bulletDelay = NULL;
	bomb = NULL;
	bombDelay = NULL;
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

	if (bomb) {
		for (int i = 0; i < bomb->size(); i++) {
			bomb->at(i)->Update(dt, shootBulletL_R);

			if (bomb->at(i)->IsDead())
				DeleteBomb(i);
		}
		bombDelay->Update(dt);
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

	if (bomb) {
		for (int i = 0; i < bomb->size(); i++) {
			bomb->at(i)->Render(Window);

			if (bomb->at(i)->IsDead())
				bomb->erase(bomb->begin() + i);
		}
	}

	Entity::Render(Window);
}

void Plane::AddBullet(float FireRate, bool L_R, float StartRate)
{
	bullet = new std::vector<Projectile*>();
	shootBulletL_R = L_R;
	bulletDelay = new Timer(FireRate, StartRate);
}

void Plane::AddBomb(float FireRate, bool L_R, float StartRate)
{
	bomb = new std::vector<Projectile*>();
	shootBmobL_R = L_R;
	bombDelay = new Timer(FireRate, StartRate);
}

void Plane::ShootBullet(const std::string& string, const sf::Vector2f& Pos, const sf::Vector2f& Scale, float Speed)
{
	if (bulletDelay->IsEnd()) {
		bullet->push_back(new Projectile(string, Pos, Scale, Speed));
		bulletDelay->Reset();
	}
}

void Plane::ShootBomb(const std::string& string, const sf::Vector2f& Pos, const sf::Vector2f& Scale, float Speed)
{
	if (bombDelay->IsEnd()) {
		bomb->push_back(new Projectile(string, Pos, Scale, Speed));
		bombDelay->Reset();
	}
}

std::vector<Projectile*>& Plane::GetBullet()
{
	return *bullet;
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

void Plane::DeleteBomb(int i)
{
	if (bomb) {
		if (bomb->at(i)) {
			bomb->erase(bomb->begin() + i);
		}
	}
}
