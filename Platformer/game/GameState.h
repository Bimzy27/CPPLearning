#pragma once
#include <vector>
#include <GameStateObserver.h>
#include <string>

class GameState
{
protected:
    GameState(const int maxHealth_) : maxHealth(maxHealth_), curHealth(maxHealth_)
    {
    }
    static GameState* instance;
    int maxHealth;
    int curHealth;

public:
    /**
     * Singletons should not be cloneable.
     */
    GameState(GameState& other) = delete;
    /**
     * Singletons should not be assignable.
     */
    void operator=(const GameState&) = delete;

    static GameState* GetInstance();

	int getHealth();
	void loseHealth(int health);
	void addObserver(HealthObserver* observer);
	void removeObserver(HealthObserver* observer);
	void Initialize();
	void Deinitialize();

private:
	std::vector<HealthObserver*> observers;
};	