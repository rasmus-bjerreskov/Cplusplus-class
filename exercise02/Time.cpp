#include "Time.h"
#include <iostream>
#include <iomanip>

using namespace std;
Time::Time() {
	hour = 0;
	minute = 0;
}

void Time::read(const char* s) {
	cout << s << endl;
	cout << "Hours: ";
	cin >> hour;
	while (hour < 0 || hour > 23) {
		cout << "Invalid hour";
		cin >> hour;
	}

	cout << "Minutes" << endl;
	cin >> minute;
	while (minute < 0 || minute > 59) {
		cout << "Invalid minute." << endl;
		cin >> minute;
	}
}

bool Time::lessThan(Time t2)
{
	if ((hour * 60 + minute) < (t2.hour * 60 + t2.minute))
		return true;
	else
		return false;

}

Time Time::subtract(Time t2)
{
	Time tmp;
	int diff, min1, min2;

	min1 = minute + hour * 60;
	min2 = t2.minute + t2.hour * 60;
	diff = min1 - min2;

	tmp.hour = diff / 60;
	tmp.minute = diff % 60;

	return tmp;
}

void Time::display()
{
	cout << setiosflags(ios::right); cout << setfill('0') 
		 << setw(2) << hour; cout << ":" << setfill('0') << setw(2) << minute;
}
