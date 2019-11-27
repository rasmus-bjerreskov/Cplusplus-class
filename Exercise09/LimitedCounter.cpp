#include "LimitedCounter.h"

LimitedCounter::LimitedCounter(int cnt0, int limit0) : Counter(cnt0)
{
	limit = limit0;
}

void LimitedCounter::setObserver(Observer* obs)
{
	this->obs = obs;
}

LimitedCounter& LimitedCounter::operator++()
{
	if (getCount() < limit)
		Counter::operator++();
	return *this;
}

LimitedCounter LimitedCounter::operator++(int) {
	LimitedCounter old(*this);
	if (getCount() < limit)
		operator++();

	return old;
}
