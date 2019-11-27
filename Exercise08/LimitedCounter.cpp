#include "LimitedCounter.h"

LimitedCounter::LimitedCounter(int cnt0, int limit0) : Counter(cnt0)
{
	limit = limit0;
}

LimitedCounter& LimitedCounter::operator++()
{
	if (getCount() < limit)
		Counter::operator++();
	return *this;
}

LimitedCounter LimitedCounter::operator++(int) {
	LimitedCounter old(*this);
	operator++();

	return old;
}
