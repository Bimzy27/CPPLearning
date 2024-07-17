#include "HealthDisplay.h"
#include <raylib.h>
#include <sstream>

std::string getHealthText(int health)
{
	std::stringstream ss;
	ss << "Health: " << health;
	std::string result = ss.str();
	return result;
}

void HealthDisplay::Initialize()
{
}

void HealthDisplay::Deinitialize()
{
}

void HealthDisplay::Update()
{
	DrawText(getHealthText(curHealth).c_str(), 10, 10, 34, WHITE);
}

void HealthDisplay::onHealthChanged(int newHealth)
{
	std::cout << "Health updated: " << newHealth << std::endl;
	curHealth = newHealth;
}