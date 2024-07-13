#include "Player.h"
#include <stdio.h>
#include <raylib.h>
#include <Main.h>

const float moveSpeed = 500.0f;
Vector2 position;
Vector2 size;

void Player::Initialize()
{
	size.x = 30;
	size.y = 30;
	position.x = SCREEN_WIDTH / 2;
	position.y = SCREEN_HEIGHT / 2;
}

void Player::Deinitialize()
{

}

void Player::Update()
{
	DrawRectangle(position.x - (size.x / 2), position.y - (size.y / 2), size.x, size.y, RED);

	float deltaTime = GetFrameTime();

	if (IsKeyDown(KEY_LEFT))
	{
		position.x -= moveSpeed * deltaTime;
	}
	if (IsKeyDown(KEY_RIGHT))
	{
		position.x += moveSpeed * deltaTime;
	}
}
