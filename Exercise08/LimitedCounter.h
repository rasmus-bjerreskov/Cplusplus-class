#pragma once
#include "counter.h"
class LimitedCounter : public Counter
{
private:
	int limit;

public:
	LimitedCounter(int cnt = 0, int limit = 0);

	LimitedCounter& operator++();
	LimitedCounter operator++(int);
};

