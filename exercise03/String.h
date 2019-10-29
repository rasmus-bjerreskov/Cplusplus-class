#pragma once
#include <cstring>
#include <iostream>

using namespace std;

class String
{
private:
	char* c_string;

public:
	String(const char* s);
	String(const String& str);
	const String& operator=(const String &str);
	String operator+(const String& str) const;
	void list();
	~String();
};

