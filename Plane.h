#pragma once
#include "Entity.h"
#include "Projectile.h"
#include "ReloadSystem.h"
#include "Explotion.h"
#include "Bomb.h"
#include "SFML/Audio.hpp"

class Plane :
    public Entity
{
private:
	std::vector<Projectile*>* bullet;
	bool shootBulletL_R;
	Timer* bulletDelay;
	std::vector<sf::Music*> bulletSound;
	std::vector<Projectile*>* Rocket;
	bool shootRocketL_R;
	Timer* RocketDelay;
	std::vector<sf::Music*> rocketSound;
	ReloadSystem* bulletReloadSystem;
	ReloadSystem* RocketReloadSystem;
	std::vector<Explotion*> explotion;

	std::vector<Projectile*>* bomb;
	bool shootBombL_R;
	Timer* BombDelay;
	ReloadSystem* BombReloadSystem;
	std::vector<sf::Music*> bombSound;

public:
    Plane(const std::string& string, const sf::Vector2f& Pos, const sf::Vector2f& Scale);

	virtual void Update(float dt, sf::Sprite* TargetSprite = NULL);

    virtual void Render(sf::RenderWindow& Window) override;

	void AddBullet(float FireRate, bool L_R, int magazine = -1, float ReloadTIme = -1, float StartRate = -1);
	void RemoveBullet();
	void AddRocket(float FireRate, bool L_R, int magazine = -1, float ReloadTIme = -1, float StartRate = -1);
	void RemoveRokcet();
	void AddBomb(float FireRate, bool L_R, int magazine = -1, float ReloadTIme = -1, float StartRate = -1);
	void RemoveBomb();

	void ShootBullet(const std::string& string, const sf::Vector2f& Pos, const sf::Vector2f& Scale, float Speed, float dt = 0);
	void ShootRocket(const std::string& string, const sf::Vector2f& Pos, const sf::Vector2f& Scale, float Speed);
	void ShootBomb(const std::string& string, const sf::Vector2f& Pos, const sf::Vector2f& Scale, float Speed, float dt = 0);

	std::vector<Projectile*>& GetBullet();
	std::vector<Projectile*>& GetRocket();
	std::vector<Projectile*>& GetBomb();

	void DeleteBullet(int i);
	void DeleteRocket(int i);
	void DeleteBomb(int i);

	void AddExplotion(const sf::Vector2f& PosS, const sf::Vector2f& Scale);
};

