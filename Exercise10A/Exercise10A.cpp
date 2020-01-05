#include <utility> 
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

void main() {
	auto pair1 = make_pair(1, make_pair(string("abc"), string("def")));
	auto pair2 = make_pair(4, make_pair(string("ghij"), string("klmn")));

	cout << left << setw(3) << pair1.first << setw(6) << pair1.second.first << pair1.second.second;
}