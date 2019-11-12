#include "String.h"
#include <iostream>
using namespace std;

void main() {
	String s;
	const char* name = "abc";
	s = "Matti"; //Conversion c-string -> String
	cout << name << endl;
	strcpy_s(s, strlen(name) + 1,  name); //Conversion String -> c-string
	cout << s << endl;
}