#include "EnemySystem.h"
#include <raylib.h>
#include <Enemy.h>

void EnemySystem::Initialize()
{
}

void EnemySystem::Deinitialize()
{
}

void EnemySystem::Update()
{
	float deltaTime = GetFrameTime();
	spawnTimer += deltaTime;
	if (spawnTimer >= spawnTime)
	{
		SpawnEnemy();
	}
}

void EnemySystem::SpawnEnemy()
{
	spawnTimer = 0.0f;
	Enemy enemy = Enemy();
	//TODO create a collection of spawned enemies, and update them.
	enemy.Initialize();
}
