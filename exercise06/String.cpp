#include "String.h"

int String::OBJECT_COUNT = 0;


String::String(const char* s)
{
	++OBJECT_COUNT;
	size_t n = strlen(s);
	if (n > MAX_STRING_LENGTH)
		n = MAX_STRING_LENGTH;
	c_string = new char[n + 1];
	strncpy_s(c_string, n + 1, s, n);
}

String::String(const String& str)
{
	++OBJECT_COUNT;
	size_t n = strlen(str.c_string) ;
	if (n > MAX_STRING_LENGTH)
		n = MAX_STRING_LENGTH;
	c_string = new char[n + 1];
	strncpy_s(c_string, n + 1, str.c_string, n);
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

String String::operator+(const String& str) const{

	char* tmp;
	size_t n = strlen(c_string) + strlen(str.c_string) + 1;
	tmp = new char[n];
	strcpy_s(tmp, strlen(c_string) + 1, c_string);
	strcat_s(tmp, n, str.c_string);

	String aux(tmp);

	return aux;
}

ostream& operator<<(ostream& out, const String& str)
{
	out << str.c_string;
	return out;
}

String& String::operator++()
{
	size_t n = strlen(c_string) + 1; //9 + 1
	if (n <= MAX_STRING_LENGTH) { 
		char* s = new char[n + 1]; // \0
		strcpy_s(s, n, c_string); //at most 9 characters + \0
		delete c_string;
		c_string = s;
		strcat_s(c_string, n + 1, "X");
	}

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

const int String::get_object_count()
{
	return OBJECT_COUNT;
}

void String::list() const
{
	cout << c_string << endl;
}


String::~String()
{
	delete c_string;
	--OBJECT_COUNT;
}
