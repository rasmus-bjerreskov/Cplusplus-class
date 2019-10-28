#include "String.h"

String::String(const char* s)
{
	int n = strlen(s) + 1;
	c_string = new char[n];
	strcpy_s(c_string, n, s);
}

String::String(const String &str)
{
	int n = strlen(str.c_string) + 1;
	c_string = new char[n];
	strcpy_s(c_string, n, str.c_string);
}

void String::list()
{
	cout << c_string << endl;
}

/*
String::~String()
{
	delete c_string;
	cout << "Destructor called" << endl;
}
*/