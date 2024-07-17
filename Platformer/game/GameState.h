#pragma once
#include <vector>
#include <GameStateObserver.h>
class GameState
{
public:
	static GameState* GetInstance();

	int getHealth();
	void loseHealth(int health);
	void addObserver(HealthObserver* observer);
	void removeObserver(HealthObserver* observer);
	GameState(int maxHealth);
	void Initialize();
	void Deinitialize();

private:
	int maxHealth;
	int curHealth;
	std::vector<HealthObserver*> observers;
	static GameState* instance;
};	