#pragma once
#include <cstring>
#include <iostream>

using namespace std;

class String
{
private:
	char* c_string;

public:
	String(const char* s = "");
	String(const String& str);

	operator const char* () const;

	const String& operator=(const String& str);
	String operator+(const String& str) const;
	friend ostream& operator<<(ostream& out, String& str);
	String& operator++();
	String operator++(int);
	char& operator[](int i);

	void list();
	~String();
};