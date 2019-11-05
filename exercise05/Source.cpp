#include "String.h"

int main() {
	String s("abcdefg");
	for (int i = 0; i < 7; i++)
		cout << s[i] << " ";
	s[4] = 'X';
	for (int i = 0; i < 7; i++)
		cout << s[i] << " ";

	s++;
	++s;
	cout << s << endl;
	return 0;
}