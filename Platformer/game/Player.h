#pragma once

#include <GameObject.h>
#include <raylib.h>

class Player : GameObject
{
public:
	void Initialize() override;
	void Deinitialize() override;
	void Update() override;

	float getX();
	float getY(); 
private:

	const float moveSpeed = 500.0f;
	const float jumpForce = 300.0f;

	Vector2 position;
	Vector2 momentum;
	bool isGrounded;
};

