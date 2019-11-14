#pragma once
#include <cstring>
#include <iostream>


using namespace std;

class String
{
private:
	static const uint8_t MAX_STRING_LENGTH = 10;
	static int OBJECT_COUNT;
	char* c_string;

public:
	String(const char* s = "");
	String(const String& str);

	operator const char* () const;

	const String& operator=(const String& str);
	String operator+(const String& str) const;
	friend ostream& operator<<(ostream& out, const String& str);
	String& operator++();
	String operator++(int);
	char& operator[](int i);

	 static const int get_object_count();

	void list() const;
	~String();

};

