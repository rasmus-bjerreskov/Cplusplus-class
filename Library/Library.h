#pragma once
#include <vector>
#include "Book.h"

class Library
{
public:
	Library() {};

	bool addBook();
	void addBook(Book bk);
	void print();
	bool isDublicate(int id);
	bool borrowBook(int& book, int usr);
	bool returnBook(int& book);
	void clear();
	friend ostream& operator<<(ostream& out, const Library& lib);
	friend istream& operator>>(istream& in, Library& lib);
private:
	vector<Book> list;
	static const int AVAILABLE = 1;
	static const int BORROWED = -1;
};

