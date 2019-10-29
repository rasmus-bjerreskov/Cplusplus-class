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

const String& String::operator=(const String& str)
{
	if (this != &str) {
		delete c_string;
		int n = strlen(str.c_string) + 1;
		c_string = new char[n];
		strcpy_s(c_string, n, str.c_string);
	}
	return *this;
}

String String::operator+(const String &str) const
{
	int l1 = strlen(c_string);
	int l2 = strlen(str.c_string);
	char* s = new char[l1 + l2 + 1];
	strcpy_s(s, l1, c_string);
	strcpy_s(s + l1, l2 + 1, str.c_string);

	String aux(s);
	delete(s);

	return s;
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
