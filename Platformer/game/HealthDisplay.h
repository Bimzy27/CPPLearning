#pragma once
#include <iostream>
#include <GameStateObserver.h>
#include "GameObject.h"

class HealthDisplay : public HealthObserver, GameObject
{
public:
    void Initialize() override;
    void Deinitialize() override;
    void Update() override;
    void onHealthChanged(int newHealth) override;
private:
    int curHealth;
};