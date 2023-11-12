#pragma once

#include <iostream>
class Timer
{
private:
	float timer;
	float maxTimer;

public:
	Timer(float MaxTimer, float StartTime = -1);

	void Update(float dt);

	bool IsEnd();

	void Reset();

	float CurrentTime();
	float MaxTime();
};

