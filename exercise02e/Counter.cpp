#include "Counter.h"

void Counter::reset()
{
	count = 0;
}

int Counter::getCount()
{
	return count;
}

void Counter::increment()
{
	count++;
}
