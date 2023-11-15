#include "HealthComponent.h"

HealthComponent::HealthComponent(sf::Sprite& Sprite, int MaxHealth) : sprite(Sprite)
{
	maxHealth = MaxHealth;
	currentHealth = maxHealth;
	srand(time(0));
	healthBarFrame.setFillColor(sf::Color::Transparent);
	healthBarFrame.setSize(sf::Vector2f(sprite.getGlobalBounds().width / 2, sprite.getGlobalBounds().height * 0.20));
	healthBarFrame.setPosition(sf::Vector2f(sprite.getPosition().x, sprite.getPosition().y - healthBarFrame.getSize().y));
	healthBarFrame.setOutlineThickness(-1.f);
	healthBarFrame.setOutlineColor(sf::Color::Black);

	healthBar.setFillColor(sf::Color::Red);
	healthBar.setOutlineColor(sf::Color::Transparent);
	healthBar.setSize(healthBarFrame.getSize());
	healthBar.setPosition(healthBarFrame.getPosition());

}

void HealthComponent::Update(float dt)
{
	healthBarFrame.setSize(sf::Vector2f(sprite.getGlobalBounds().width * 0.6, sprite.getGlobalBounds().height * 0.20));
	healthBarFrame.setPosition(sf::Vector2f(sprite.getPosition().x - healthBarFrame.getSize().x / 2,
		sprite.getPosition().y - healthBarFrame.getSize().y - 30));

	healthBar.setSize(sf::Vector2f(healthBarFrame.getSize().x * (float(currentHealth) / float(maxHealth)), healthBarFrame.getSize().y));
	healthBar.setPosition(healthBarFrame.getPosition());

	for (int i = 0; i < damageText.size(); i++)
	{
		if (damageText[i]->GetText().getFillColor().a <= 0)
		{
			damageText.erase(damageText.begin() + i);
			return;
		}

		damageText[i]->GetText().move(0, -200 * dt);
		damageText[i]->GetText().setFillColor(sf::Color(damageText[i]->GetText().getFillColor().r, damageText[i]->GetText().getFillColor().g,
			damageText[i]->GetText().getFillColor().b, damageText[i]->GetText().getFillColor().a - dt / 100));
	}
}

void HealthComponent::Render(sf::RenderWindow& Window)
{
	Window.draw(healthBarFrame);
	Window.draw(healthBar);

	for (int i = 0; i < damageText.size(); i++)
	{
		damageText[i]->Render(Window);
	}
}

void HealthComponent::OnHit(int Damage)
{
	currentHealth -= Damage;
	if (Damage == 1 || Damage == 2)
		damageText.push_back(new Text("-" + std::to_string(Damage), sprite.getPosition(), sf::Vector2f(1.5, 1.5), sf::Color::Red));
	else if (Damage >= 3 && Damage <= 5)
		damageText.push_back(new Text("-" + std::to_string(Damage), sprite.getPosition(), sf::Vector2f(1.5, 1.5), sf::Color::Magenta));
	else if(Damage <= 10 && Damage > 5)
		damageText.push_back(new Text("-" + std::to_string(Damage), sprite.getPosition(), sf::Vector2f(2.5, 2.5), sf::Color(255, 165, 0)));
}

int HealthComponent::GetHealth()
{
	return currentHealth;
}
