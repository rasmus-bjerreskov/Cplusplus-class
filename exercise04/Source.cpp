#include "String.h"

int main() {
	String s("abcdefg");
	String z("opq");
	for (int i = 0; i < 7; i++)
		cout << s[i] << " ";
	s[4] = 'X';
	for (int i = 0; i < 7; i++)
		cout << s[i] << " ";
	s++;
	++s;
	s = s + z;
	cout << s << endl;
	return 0;
}
