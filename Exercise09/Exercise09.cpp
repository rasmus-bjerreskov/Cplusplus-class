#include "LimitedCounter.h"
#include "RoundupCounter.h"

void UseCounter(Counter *target, int incr);

int main() {
	LimitedCounter counterA(0, 5);
	RoundupCounter counterB(0, 5);
	UseCounter(&counterA, 8); UseCounter(&counterB, 8);
	cout << "Counter A: " << counterA << endl; // output should be 5
	cout << "Counter B: " << counterB << endl; // output should be 2
	return 0;
}

void UseCounter(Counter *target, int incr)
{
	for (int i = 0; i < incr; i++)
		target->operator++();
}