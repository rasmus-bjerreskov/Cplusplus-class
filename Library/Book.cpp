#include "Book.h"

Book::Book(int id0, string ti0) : id(id0), title(ti0)
{
	available = true;
	returnBy = 0;
	userId = 0;
}

Book::Book(const int id0, int usr0, time_t ret0, const string ti0) : id(id0), userId(usr0), returnBy(ret0), title(ti0)
{
	available = false;
}

void Book::borrow(int usr)
{
	available = false;
	returnBy = chrono::system_clock::to_time_t(chrono::system_clock::now()) + LOAN_PERIOD;
	userId = usr;
}

void Book::returnBook()
{
	available = true;
	userId = 0;
	returnBy = 0;
}

bool Book::getAvailable()
{
	return available;
}

int Book::getId()
{
	return id;
}

//Pretty print
void Book::print()
{
	if (!available) {
		cout << left << setw(8) << id << setw(35) << title << "Borrowed by user: "<< setw(8) << userId  << " To be returned by: " << ctime(&returnBy); //no linebreak because ctime inserts a linebreak
	}
	else
		cout <<left << setw(8) << id << setw(35) << title << endl;
}

//For use with file stream
ostream& operator<<(ostream& out, const Book& bk)
{
	if (bk.available) {
		out << " " << bk.id << " " << bk.title;
	}

	else {
		out << " " << bk.id << " " << bk.userId << " " << bk.returnBy << " " << bk.title;
	}

	return out;
}