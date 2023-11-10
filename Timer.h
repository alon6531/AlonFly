#pragma once

#include <iostream>
class Timer
{
private:
	float timer;
	float maxTimer;

public:
	Timer(float MaxTimer);

	void Update(float dt);

	bool IsEnd();

	void Reset();
};

