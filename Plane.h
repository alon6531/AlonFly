#pragma once
#include "Entity.h"
#include "Projectile.h"

class Plane :
    public Entity
{
private:
	std::vector<Projectile*>* bullet;
	bool shootBulletL_R;
	Timer* bulletDelay;
	std::vector<Projectile*>* bomb;
	bool shootBmobL_R;
	Timer* bombDelay;


public:
    Plane(const std::string& string, const sf::Vector2f& Pos, const sf::Vector2f& Scale);

	virtual void Update(float dt, sf::Sprite* TargetSprite = NULL);

    virtual void Render(sf::RenderWindow& Window) override;

	void AddBullet(float FireRate, bool L_R, float StartRate = -1);
	void AddBomb(float FireRate, bool L_R, float StartRate = -1);

	void ShootBullet(const std::string& string, const sf::Vector2f& Pos, const sf::Vector2f& Scale, float Speed);
	void ShootBomb(const std::string& string, const sf::Vector2f& Pos, const sf::Vector2f& Scale, float Speed);

	std::vector<Projectile*>& GetBullet();
	std::vector<Projectile*>& GetBomb();

	void DeleteBullet(int i);
	void DeleteBomb(int i);
};

