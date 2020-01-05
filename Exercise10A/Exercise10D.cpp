#include <iostream>
#include <algorithm>
using namespace std;
#define smallest(a,b) min(a,b)
struct arr {
	static const int n = 10;
	int a[n];
	int elements() {
		int k = 0, * p = &a[0];
		// count the number of array elements
		while (smallest(p++, &a[n]) != &a[n])
			k++;
		return k;
	}
	int size() {
		return n;
	}
};
int main() {
	arr a;
	cout << "Elements: " << a.elements() << ", expecting: " << a.size() << endl;
	system("PAUSE");
	return EXIT_SUCCESS;
}