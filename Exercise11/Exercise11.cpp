#include <utility>
#include <iostream>
#include <vector>
#include <time.h>
#include <algorithm>
#include <iterator>

using namespace std;

//Ordinary function 
int randGen_1() 
{ 
	return rand() % 10 + 1; 
} //Function object 
class RandGen_2 { 
public: 
	RandGen_2(): numbers() 
	{
		srand(time(NULL));
	} 
	int operator()(); 
private: vector<int> numbers; 
}; 

class Print {
public:
	Print() : count(0) {};
	void operator()(int out);

private:
	int count;
};

int main(void) { 
	vector<int> numbers_a(7); 
	vector<int> numbers_b(7);
	vector<int> matches;
	ostream_iterator<double> ostr_it(cout, " ");

	RandGen_2 randGen_2a; 
	RandGen_2 randGen_2b;
	generate(numbers_a.begin(), numbers_a.end(), randGen_2a); 
	generate(numbers_b.begin(), numbers_b.end(), randGen_2b);

	copy(numbers_a.begin(), numbers_a.end(), ostr_it);
	cout << endl;
	copy(numbers_b.begin(), numbers_b.end(), ostr_it);
	cout << endl;

	sort(numbers_a.begin(), numbers_a.end());
	sort(numbers_b.begin(), numbers_b.end());

	set_intersection(numbers_a.begin(), numbers_a.end(), numbers_b.begin(), numbers_b.end(), back_inserter(matches));
	


	for_each(matches.begin(), matches.end(), Print());

	return 0;

} 

void Print::operator()(int out) {
	++count;
	cout << "#" << count << " " << out << endl;
}

int RandGen_2::operator()() { 
	int number; 
	do { 
		number = rand() % 37 + 1; 
	} while(find(numbers.begin(), numbers.end(), number) != numbers.end()); 
	numbers.push_back(number); return number; }