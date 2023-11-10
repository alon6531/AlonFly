#include "Timer.h"

Timer::Timer(float MaxTimer)
{
	maxTimer = MaxTimer;
	timer = maxTimer;
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
