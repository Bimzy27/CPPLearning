#include "HUD.h"

void HUD::Initialize()
{
	healthDisplay.Initialize();
}

void HUD::Deinitialize()
{
	gameState->removeObserver(&healthDisplay);
	healthDisplay.Deinitialize();
}

void HUD::Update()
{
	healthDisplay.Update();
}

HUD::HUD(GameState* gameState) 
{
	this->gameState = gameState;
	gameState->addObserver(&healthDisplay);
}