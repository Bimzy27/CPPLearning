#include "Enemy.h"
#include <raylib.h>
#include <Main.h>

void Enemy::Initialize()
{
	target.x = 0;
	target.y = 0;

	position.x = -1000;
	position.y = GROUND_HEIGHT - (CELL_SIZE / 2);
}

void Enemy::Deinitialize()
{

}

void Enemy::Update()
{
	DrawRectangle(position.x - (CELL_SIZE / 2), position.y - (CELL_SIZE / 2), CELL_SIZE, CELL_SIZE, DARKPURPLE);

	float deltaTime = GetFrameTime();

	//Vector2 direction = (position - target);
}