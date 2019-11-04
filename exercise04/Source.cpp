#include "String.h"

int main() {
	String s1("abcedf");
	String s2("ghijklmn");
	String sum;
	cout << "String 1 is:" << s1 << endl;
	cout << "String 2 is:" << s2 << endl;
	sum = s1 + s2;
	cout << "Sum is :" << sum; // output should be
	// abcdefghijklmn
	// This should also work
	sum = sum;
	cout << "Sum is still :" << sum; // output should
	// still be abcdefghijklmn
	return 0;
}