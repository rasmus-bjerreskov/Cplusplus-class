#include "LimitedCounter.h"

LimitedCounter::LimitedCounter(int val0, int limit0)
{
	cntr = new Counter(val0);
	limit = limit0;
}

LimitedCounter::LimitedCounter(const LimitedCounter& ref)
{
	limit = ref.limit;
	cntr = new Counter(ref.getCount());
}


LimitedCounter& LimitedCounter::operator++()
{
	if (cntr->getCount() < limit)
		cntr->operator++();

	return *this;
}

LimitedCounter LimitedCounter::operator++(int)
{
	LimitedCounter aux(*this);
	operator++();
	return aux;
}

LimitedCounter& LimitedCounter::operator=(const LimitedCounter& c2)
{
	if (this != &c2) {
		return *this;
		limit = c2.limit;
		delete cntr;
		cntr = new Counter(c2.getCount());
	}
	return *this;
}

bool LimitedCounter::operator<(const LimitedCounter& c2) const
{
	return *cntr < *c2.cntr;
}

void LimitedCounter::reset()
{
	cntr->reset();
}

int LimitedCounter::getCount() const
{
	return cntr->getCount();
}

LimitedCounter::~LimitedCounter()
{
	delete cntr;
}

ostream& operator<<(ostream& out, const LimitedCounter& c)
{
	return out << *c.cntr;
}
