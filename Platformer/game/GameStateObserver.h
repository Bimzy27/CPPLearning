#pragma once

class HealthObserver {
public:
	virtual void onHealthChanged(int newHealth) = 0;
};