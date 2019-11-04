#include "String.h"

String::String(const char* s)
{
	size_t n = strlen(s) + 1;
	c_string = new char[n];
	strcpy_s(c_string, n, s);
}


String::String(const String& str)
{
	size_t n = strlen(str.c_string) + 1;
	c_string = new char[n];
	strcpy_s(c_string, n, str.c_string);
}

const String& String::operator=(const String& str)
{
	if (this != &str) {
		delete c_string;
		size_t n = strlen(str.c_string) + 1;
		c_string = new char[n];
		strcpy_s(c_string, n, str.c_string);
	}
	return *this;
}

String String::operator+(const String& str) const
{
	size_t n = strlen(c_string) + sizeof(str.c_string) + 1;
	char* s = new char[n];

	strcpy_s(s, strlen(c_string) + 1, c_string);
	strcat_s(s, n, str.c_string);

	String aux(s);
	delete[]s;

	return aux;
}

String& String::operator++()
{
	String aux("X");
	*this = *this + aux;
	return *this;
}

void String::list()
{
	cout << c_string << endl;
}


String::~String()
{
	delete c_string;
}

ostream& operator<<(ostream& out, String str)
{
	out << str.c_string;
	return out;
}