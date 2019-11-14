#include "String.h"
#include <iostream>
using namespace std;

void display(const String& p);
int main() {
	cout << String::get_object_count() << endl;
	{
		String array[4];
		// display the number of String objects
		cout << String::get_object_count() << endl;
	}
	cout << String::get_object_count() << endl;
	String s = "abc";
	for (int i = 0; i < 15; ++i)
		++s;

	cout << s << endl;
	// display the number of String objects
	return 0;
}

void display(const String& p) {
	for (int i = 0; i < strlen(p); ++i) {
		cout << p[i];
	}
	cout << endl;
}