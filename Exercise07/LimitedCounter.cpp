#include "LimitedCounter.h"

LimitedCounter::LimitedCounter(int val0, int limit0) : cntr(val0)
{
	limit = limit0;
}


LimitedCounter& LimitedCounter::operator++()
{
	if (cntr.getCount() < limit)
		cntr.operator++();

	return *this;
}

LimitedCounter LimitedCounter::operator++(int)
{
	LimitedCounter aux(*this);
	operator++();
	return aux;
}

bool LimitedCounter::operator<(const LimitedCounter& c2) const
{
	return cntr < c2.cntr;
}

void LimitedCounter::reset()
{
	cntr.reset();
}

int LimitedCounter::getCount() const
{
	return cntr.getCount();
}

ostream& operator<<(ostream& out, const LimitedCounter& c)
{
	return out << c.cntr;
}
