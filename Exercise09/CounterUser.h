#pragma once
#include "Observer.h"
#include "LimitedCounter.h"
class CounterUser : public Observer
{
private:
	LimitedCounter* counter;
public:

};

