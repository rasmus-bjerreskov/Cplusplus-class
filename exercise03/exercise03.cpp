#include "String.h"
#ifdef _DEBUG // Active only in Debug Configuration
#define _CRTDBG_MAP_ALLOC // Visual Studio Mem Leak detector activated
#include <crtdbg.h> // runtime debug functions are declared here
#endif
void f(int i) {
	String s("abcdefghijklmnopqrstuvwxyz");
	if (i % 100 == 0)
		s.list();
}
int main() {
	int i = 0;
	_CrtMemState memory; // C/C++ runtime memory management state storage
	while (i < 1000) {
		f(i++);
		// dump memory management state
		_CrtMemCheckpoint(&memory); _CrtMemDumpStatistics(&memory);
	}
	_CrtDumpMemoryLeaks(); // check if there were memory leaks

	return 0;
}