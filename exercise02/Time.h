#pragma once
class Time
{
private:
	int hour;
	int minute;

public:
	Time();
	void read(const char*);
	bool lessThan(Time t2);
	Time subtract(Time t2);
	void display();
};

