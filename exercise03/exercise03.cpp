#include "String.h"

void f(String &s);

int main() {
	String s("abcdefg");
	s.list();
	f(s);
	s.list();
}

void f(String &s) {
	s.list();
}