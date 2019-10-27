#include <iostream>
#include <cstdlib>
using namespace std;

float avg(int* a, int n);
int main() {
	int n;
	
	cout << "How many random numbers?" << endl;
	cin >> n;

	int* a = new int[n];

	for (int i = 0; i < n; i++) {
		a[i] = rand() % 100;
		cout << a[i] << endl;
	}
	cout << "\n\nAverage: " << avg(a, n) << endl;

	delete []a;
}

float avg(int* a, int n) {
	int sum = 0;

	for (int i = 0; i < n; i++)
		sum += a[i];

	return (float)sum / n;
}