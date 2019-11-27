#pragma once
#include "counter.h"
#include "Observer.h"
class LimitedCounter : public Counter
{
private:
	int limit;
	Observer* obs;

public:
	LimitedCounter(int cnt = 0, int limit = 0);

	void setObserver(Observer*);

	LimitedCounter& operator++();
	LimitedCounter operator++(int);
};

