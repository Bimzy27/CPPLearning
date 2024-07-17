#pragma once
#include <iostream>
#include <HealthDisplay.h>
#include <GameState.h>
#include "GameObject.h"

class HUD : public GameObject
{
public:
	void Initialize() override;
	void Deinitialize() override;
	void Update() override;
	HUD(GameState* gameState);
private:
	HealthDisplay healthDisplay;
	GameState* gameState;
};