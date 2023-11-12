#pragma once
class HealthComponent
{
private:
	int currentHealth;
	int maxHealth;
public:
	HealthComponent(int MaxHealth);

	void OnHit(int Damage);

	int GetHealth();
};

