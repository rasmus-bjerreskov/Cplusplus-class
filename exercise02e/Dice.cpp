#include "Dice.h"

void Dice::initialize()
{
	srand((int)time(NULL));
}

float Dice::roll()
{
	return (float)rand() / (RAND_MAX + 1);
}
