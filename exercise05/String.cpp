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

String::operator const char* () const
{
	return c_string;
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
	String aux;
	size_t n = strlen(c_string) + strlen(str.c_string) + 1;

	delete aux.c_string;
	aux.c_string = new char[n];

	strcpy_s(aux.c_string, strlen(c_string) + 1, c_string);
	strcat_s(aux.c_string, n, str.c_string);

	return aux;
}

ostream& operator<<(ostream& out, const String& str)
{
	out << str.c_string;
	return out;
}

String& String::operator++()
{
	size_t n = strlen(c_string) + 2;
	char* s = new char[n];
	strcpy_s(s, n, c_string);
	delete c_string;
	c_string = s;
	strcat_s(c_string, n, "X");

	return *this;
}

String String::operator++(int)
{
	String aux(*this);
	this->operator++();
	return aux;
}

char& String::operator[](int i)
{
	size_t n = strlen(c_string);
	if (i >= n) {
		return c_string[n - 1];
		cout << "Out of bounds";
	}
	return c_string[i];
}

void String::list() const
{
	cout << c_string << endl;
}


String::~String()
{
	delete c_string;
}
