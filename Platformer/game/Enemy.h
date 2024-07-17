#pragma once

#include <GameObject.h>
#include <raylib.h>

class Enemy : public GameObject
{
public:
	void Initialize() override;
	void Deinitialize() override;
	void Update() override;
private:
	const float moveSpeed = 300.0f;

	Vector2 target;
	Vector2 position;
};