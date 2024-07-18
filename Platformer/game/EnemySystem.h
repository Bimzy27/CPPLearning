#pragma once
#include "GameObject.h"

class EnemySystem : public GameObject
{
public:
    void Initialize() override;
    void Deinitialize() override;
    void Update() override;
private:
    void SpawnEnemy();
    const float spawnTime = 10.0f;
    float spawnTimer = 0.0f;
};

