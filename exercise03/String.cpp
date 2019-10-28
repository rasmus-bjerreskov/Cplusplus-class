#include "String.h"

String::String(const char* s)
{
	c_string = new char[11];
	strcpy_s(c_string, 11, s);
}

String::String(const String& str)
{
	c_string = new char[11];
	strcpy_s(c_string, 11, str.c_string);
}

void String::list()
{
	cout << c_string << endl;
}

String::~String()
{
	delete c_string;
	cout << "Destructor called" << endl;
}
