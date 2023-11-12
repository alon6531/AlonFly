#include "Timer.h"


Timer::Timer(float MaxTimer, float StartTime)
{
	if (StartTime == -1)
		StartTime = MaxTimer;
	maxTimer = MaxTimer;
	timer = StartTime;
}

void Timer::Update(float dt)
{
	timer -= dt;
}

bool Timer::IsEnd()
{
	return timer <= 0;
}

void Timer::Reset()
{
	timer = maxTimer;
}

float Timer::CurrentTime()
{
	return timer;
}

float Timer::MaxTime()
{
	return maxTimer;
}
