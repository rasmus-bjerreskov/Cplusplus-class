#pragma once
#include <cstring>
#include <iostream>

using namespace std;

class String
{
private:
	char* c_string;

public:
	String();
	String(const char* s);
	String(const String& str);

	const String& operator=(const String &str);
	String operator+(const String& str) const;
	friend ostream& operator<<(ostream& out, String str);
	void list();
	~String();
};

