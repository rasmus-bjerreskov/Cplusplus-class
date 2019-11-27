#include "RoundupCounter.h"

RoundupCounter::RoundupCounter(int c0, int l0) : Counter(c0)
{
	limit = l0;
}

RoundupCounter& RoundupCounter::operator++()
{
	if (getCount() < limit) {
		Counter::operator++();
	}
	else
		Counter::reset();

	return *this;
}

RoundupCounter RoundupCounter::operator++(int)
{
	RoundupCounter old(*this);
	this->operator++();

	return old;
}
