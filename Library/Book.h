#pragma once
#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <chrono>
#include <ctime>
#include <iomanip>
using namespace std;


class Book
{
public:
	Book(const int id0, const string ti0);
	Book(const int id0, int usr0, time_t ret0, const string ti0);

	void borrow(int usr);
	void returnBook();
	bool getAvailable();
	int getId();
	void print();
	friend ostream& operator<<(ostream& out, const Book& str);
	
private:
	int id;
	string title;
	bool available;
	time_t returnBy;
	int userId;
	static const int LOAN_PERIOD = 14 * 86400; //14 days
};

