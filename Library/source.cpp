#define _CRT_SECURE_NO_WARNINGS 1
#include <fstream>
#include "Library.h"

using namespace std;

int login();
void preload(Library& lib);
int main() {
	Library lib;
	int selec = 0;
	int usr = 0;
	cout << "== Library ==" << endl;
	cout << "Welcome. Please enter your nummerical user ID: ";
	usr = login();

	cout << "Options:" << endl;
	cout << "1:" << setfill('.') << setw(30) << "Change user ID\n"
		<< "2:" << setw(30) << "List available books\n"
		<< "3:" << setw(30) << "Borrow a book\n"
		<< "4:" << setw(30) << "Return a book\n"
		<< "5:" << setw(30) << "Save library to file\n"
		<< "6:" << setw(30) << "Add records from file\n"
		<< "7:" << setw(30) << "Clear library\n"
		<< "8:" << setw(30) << "Manually add book\n"
		<< "0:" << setw(30) << "Exit" << setfill(' ') << endl;	
	
	do {
		cout << "Action: ";
		cin >> selec;

		switch (selec) {
		case 1:
		{
			cout << "User ID: ";
			usr = login();
			break;
		}

		case 2:
		{
			lib.print();
			break;
		}
		case 3:
		{
			int bkid = 0;
			cout << "Enter ID of the book you wish to borrow: ";
			cin >> bkid;
			if (lib.borrowBook(bkid, usr))
				cout << "Book borrowed!" << endl;
			else
				cout << "Failed to borrow. The ID either does not exist in the library or is already borrowed." << endl;
			break;
		}

		case 4:
		{
			int bkid = 0;
			cout << "Enter ID of the book you wish to return: ";
			if (lib.returnBook(bkid))
				cout << "Book returned!";
			else
				cout << "Failed to return book. Book either does not exist in the library or is not registered as borrowed." << endl;
			break;
		}
		
		case 5:
		{
			string filename;
			fstream outfile;
			cout << "Name of the file to save to. \nIf a file with the same name already exists, it will be overwritten: ";
			cin >> filename;

			outfile.open(filename, fstream::out | fstream::trunc);
			if (outfile << lib)
				cout << "Library saved." << endl;
			else
				cout << "Failed to save to " << filename << endl;
			outfile.close();
			break;
		}

		case 6:
		{
			string filename;
			fstream infile;
			cout << "Name of the file to read from. \nAny books already in the library will not be added: ";
			cin >> filename;
			infile.open(filename, fstream::in);
			infile >> lib;
			if (infile.rdstate() & fstream::failbit)
				cout << "Succesfully added the file to the library" << endl;
			else
				cout << "Failed to read file" << endl;
			break;
		}

		case 7:
		{
			char c;
			cout << "Are you sure you want to remove all books in the current library (y/n): ";
			cin >> c;
			if (c == 'y') {
				cout << "Welcome to Baghdad, anno 1258." << endl;
				lib.clear();
			}
			break;
		}

		case 8:
		{
			cout << "Enter book ID and title, separated by space ([ID] [Title]): ";
			if (lib.addBook())
				cout << "Book succesfully added!" << endl;
			else
				cout << "Failed to add book. Invalid input or the book already exists in the library";
			break;
		}

		case 9:
			preload(lib);
			break; 

		default:
			break;
		}
	} while (selec != 0);

	return 0;
}

int login() {
	int usr;
	while (!(cin >> usr)) {
		cout << "Invalid user ID. ID must be a number: ";
		cin.clear();
		cin.ignore();
	}
	return usr;
}

void preload(Library& lib) {
	Book bk1(100, "Joye of Snacks");
	Book bk2(101, "World of Poo");
	Book bk3(102, "The Necrotelecomnicon");
	Book bk4(103, "Where's My Cow?");
	Book bk5(104, "The Octavo");
	Book bk6(105, "What I Did on My Holidays");
	Book bk7(106, "Twurp's Peerage");
	lib.addBook(bk1);
	lib.addBook(bk2);
	lib.addBook(bk3);
	lib.addBook(bk4);
	lib.addBook(bk5);
	lib.addBook(bk6);
	lib.addBook(bk7);
}