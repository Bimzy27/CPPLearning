#include "Player.h"
#include <stdio.h>
#include <raylib.h>
#include <Main.h>
#include <algorithm>

float getGroundHeight()
{
	return GROUND_HEIGHT - (CELL_SIZE / 2);
}

void Player::Initialize()
{
	position.x = 0;
	position.y = SCREEN_HEIGHT / 2;
}

void Player::Deinitialize()
{

}

void Player::Update()
{
	DrawRectangle(position.x - (CELL_SIZE / 2), position.y - (CELL_SIZE / 2), CELL_SIZE, CELL_SIZE, RED);

	float deltaTime = GetFrameTime();

	// Lateral movement
	if (IsKeyDown(KEY_LEFT))
	{
		position.x -= moveSpeed * deltaTime;
	}
	if (IsKeyDown(KEY_RIGHT))
	{
		position.x += moveSpeed * deltaTime;
	}

	// Apply gravity
	isGrounded = position.y >= getGroundHeight();

	if (isGrounded && IsKeyPressed(KEY_SPACE))
	{
		momentum.y += jumpForce;
	}

	if (isGrounded)
	{
		momentum.y = std::max(0.0f, momentum.y);
		position.y = getGroundHeight();
	}
	else
	{
		momentum.y -= GRAVITY * deltaTime;
	}

	position.y -= momentum.y * deltaTime;
}

float Player::getX()
{
	return position.x;
}

float Player::getY()
{
	return position.y;
}