#pragma once
#include "counter.h"
class LimitedCounter
{
	friend ostream& operator<<(ostream& out, const LimitedCounter& c);

private:
	Counter cntr;
	int limit;

public:
	LimitedCounter(int val0 = 0, int limit0 = 0);

	LimitedCounter& operator++();
	LimitedCounter operator++(int);
	bool operator<(const LimitedCounter& c2) const;
	void reset();
	int getCount() const;
};

