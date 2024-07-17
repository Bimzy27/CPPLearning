#include "GameState.h"
#include <utility>
#include <stdio.h>

GameState* GameState::instance = nullptr;;

GameState* GameState::GetInstance()
{
	if (instance == nullptr) {
		instance = new GameState(10);
	}
	return instance;
}

int GameState::getHealth()
{
	return curHealth;
}

void GameState::loseHealth(int health)
{
	curHealth = std::max(curHealth - health, 0);

	for (auto observer : observers)
	{
		observer->onHealthChanged(curHealth);
	}
}

void GameState::addObserver(HealthObserver* observer) 
{
	observers.push_back(observer);
}

void GameState::removeObserver(HealthObserver* observer) 
{
	observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
}

void GameState::Initialize()
{
	for (auto observer : observers)
	{
		observer->onHealthChanged(curHealth);
	}
}

void GameState::Deinitialize()
{
}
