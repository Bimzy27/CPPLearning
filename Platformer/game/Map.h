#pragma once

#include <GameObject.h>

class Map : public GameObject
{
public:
	void Initialize() override;
	void Deinitialize() override;
	void Update() override;
};

