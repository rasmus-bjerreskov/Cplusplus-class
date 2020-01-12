// find_if example
#include <iostream>     // std::cout
#include <algorithm>    // std::find_if
#include <vector>       // std::vector

bool IsOdd(int i) {
    return ((i % 2) == 1);
}

int main() {
    std::vector<int> myvector;

    myvector.push_back(10);
    myvector.push_back(2);
    myvector.push_back(40);
    myvector.push_back(3);

    std::vector<int>::iterator it = std::find_if(myvector.begin(), myvector.end(), IsOdd);
    if (it != myvector.end())
    std::cout << "The first odd value is " << *it << '\n';

    return 0;
}