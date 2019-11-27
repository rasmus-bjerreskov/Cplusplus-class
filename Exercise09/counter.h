/* Header file of Counter Class*/
#pragma once
#include <iostream>
using namespace std;
//Class definition
class Counter {
    friend ostream &operator<<(ostream &out, const Counter &c);
    public:
        Counter(int n0 = 0);
        virtual Counter &operator++();
        Counter operator++(int);
        bool operator<(const Counter &c2) const;
        void reset();
	int getCount() const;

    private:
        int count;
};

