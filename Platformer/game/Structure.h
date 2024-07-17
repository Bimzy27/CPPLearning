#pragma once
#include "GameObject.h"

class Structure : public GameObject
{
public:
	void Initialize() override;
	void Deinitialize() override;
	void Update() override;
private:
};
