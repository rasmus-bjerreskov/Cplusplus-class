#pragma once
#include "counter.h"
class RoundupCounter : public Counter
{
public:
	RoundupCounter(int c0 = 0, int l0 = 0);
	RoundupCounter& operator++();
	RoundupCounter operator++(int);
private:
	int limit;
};

