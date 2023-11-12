#include "HealthComponent.h"

HealthComponent::HealthComponent(int MaxHealth)
{
	maxHealth = MaxHealth;
	currentHealth = maxHealth;
}

void HealthComponent::OnHit(int Damage)
{
	currentHealth -= Damage;
}

int HealthComponent::GetHealth()
{
	return currentHealth;
}
