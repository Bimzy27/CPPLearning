#include "Enemy.h"
#include <raylib.h>
#include <Main.h>
#include <VectorUtility.h>
#include <stdio.h>

void Enemy::Initialize()
{
	position.x = -1000;
	position.y = GROUND_HEIGHT - (CELL_SIZE / 2);

	target.x = 0;
	target.y = position.y;
}

void Enemy::Deinitialize()
{

}

void Enemy::Update()
{
	DrawRectangle(position.x - (CELL_SIZE / 2), position.y - (CELL_SIZE / 2), CELL_SIZE, CELL_SIZE, DARKPURPLE);

	float deltaTime = GetFrameTime();

	Vector2 direction = Normalize(target - position);
	position = position + (direction * (deltaTime * moveSpeed));
	printf("Direction: %f <==> %f\n", direction.x, direction.y);
}