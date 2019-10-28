#include "Inspector.h"

void Inspector::setLimits(float l_bound, float u_bound)
{
	lower = l_bound;
	upper = u_bound;
}

bool Inspector::isInLimits(float test)
{
	if (test < lower || test > upper)
		return false;

	return true;
}
