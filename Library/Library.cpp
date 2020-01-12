#include "Library.h"
#include <sstream>
#include <algorithm>
#include <iomanip>
//For manually adding a book from console
bool Library::addBook()
{
	string tmp, input, name;
	int id = 0;
	
	ws(cin); //clearing input buffer of leftover newline
	getline(cin, input);
	stringstream sstream(input);

	//check validity of ID, abort if not a number
	if (!(sstream >> id)) {
		return false;
	}

	//extract title from rest of string stream
	while (!sstream.eof()) {
		sstream >> tmp;
		name += tmp;
		if (!sstream.eof())
			name += " ";
	}

	Book tmpB(id, name);
	list.push_back(tmpB);
	return true;
}

void Library::addBook(Book bk)
{
	if (!isDublicate(bk.getId()))
		list.push_back(bk);
}

//Pretty print of library content
void Library::print()
{
	cout << "\n---Books currently out for loan---" << endl;
	cout << left << setw(8) << "Id" << setw(35) << "Title" << endl;
	for (auto &it : list) {
		if (!it.getAvailable())
			it.print();
	}

	cout << "\n---Available books---" << endl;
	cout << left << setw(8) << "Id" << setw(35) << "Title" << endl;

	for (auto &it : list) {
		if (it.getAvailable())
			it.print();
	}
}

bool Library::isDublicate(int test)
{
	for (auto &it : list) {
		if (it.getId() == test)
			return true;
	}
	return false;
}

bool Library::borrowBook(int book, int usr)
{
	for (auto &it : list) {
		if (it.getId() == book && it.getAvailable()) {
			it.borrow(usr);
			return true;
		}
	}
	return false;
}

bool Library::returnBook(int bk)
{
	for (auto &it : list) {
		if (it.getId() == bk && !it.getAvailable()) {
			it.returnBook();
			return true;
		}
	}
	return false;
}

void Library::clear()
{
	list.clear();
}

//For use with file streams
ostream& operator<<(ostream& out, const Library& lib)
{
	for (auto it : lib.list) {
		if (it.getAvailable())
			out << lib.AVAILABLE << " " << it << endl;
		else
			out << lib.BORROWED << " " << it << endl;
	}
	return out;
}

//For use with file streams
istream& operator>>(istream& in, Library& lib)
{
	string tmp;
	while (getline(in, tmp)) {
		int state;
		int id0 = 0;
		int usr0 = 0;
		int ret0 = 0;
		string ti0;
		stringstream ss(tmp);
		ss >> state;

		if (state == lib.AVAILABLE && ss >> id0 || ss >> id0 >> usr0 >> ret0) {
			ws(ss); //getline leaves a whitespace preceding the title string
			getline(ss, ti0);
			if (state == lib.AVAILABLE && !lib.isDublicate(id0)) {
				Book aux(id0, ti0);
				lib.list.push_back(aux);
			}
			else if (!lib.isDublicate(id0)) {
				Book aux(id0, usr0, ret0, ti0);
				lib.list.push_back(aux);
			}
		}
		else
			in.setstate(ios::failbit);

	}
	return in;
}
