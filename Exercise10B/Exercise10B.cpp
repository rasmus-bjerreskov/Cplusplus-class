#include <vector>
#include <string>
#include <iostream>
#include <utility>
using namespace std;

void main() {
	vector<string> sv1;
	string str;

	cout << "Enter string" << endl;
	do {
		
		cin >> str;
		if (str != "stop")
			sv1.push_back(str);
	} while (str != "stop");

	auto longest = make_pair( 0, string(""));

	for (auto i : sv1) {
		int len = i.size();
			if (len > longest.first) {
				longest.first = len;
				longest.second = i;
			}
	}

	cout << "longest: " << longest.second << ", length " << longest.first << endl;
		
	for (auto i : sv1) {
		cout << i << endl;
	}

	cout << "size(): " << sv1.size() << endl;
	cout << "capacity()" << sv1.capacity() << endl;
	cout << "sizeof()" << sizeof(sv1) << endl;
}