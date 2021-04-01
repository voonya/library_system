#include <iostream>
#include "BookingUserInterface.h"


int chooseBook(int count) {
	cout << "To choose some book for booking enter book number: ";
	int bookNumber = -1;
	cin >> bookNumber;
	while (bookNumber > count || bookNumber <= 0) {
		cout << "Incorrect number, try again: ";
		cin >> bookNumber;
	}
	return bookNumber;
}

void BookingUserInterface::startDialogMenu(BookDatabase& DB, BookBooker& bookBooker, Client* client)
{
	cout << "It's menu of booking books\n";
	int number = 0;
	cout << "To view books enter '1'\n";
	cout << "To exit from booking interface enter '2'\n";
	cout << "Your input: ";
	cin >> number;
	if (number == 1) {
		showBooks(DB);
		cout << "To choose book for enter '1'\n";
		cout << "To exit from booking interface enter '2'\n";
		cout << "Your input: ";
		cin >> number;
		if (number == 2)
			return;
		int bookNumber = chooseBook(DB.getAllBooks().size());
		cout << "Your choosed book is: " << bookNumber << endl;
		cout << "To book the choosed book enter '1'\n";
		cout << "To exit from booking interface enter '2'\n";
		cout << "Your input: ";
		cin >> number;
		if (number == 1) {
			bookingTheBook(DB, bookBooker, bookNumber - 1, client);
		}
	}
}

void BookingUserInterface::showBooks(BookDatabase& DB)
{
	vector< Book > books = DB.getAllBooks();
	for (int i = 0; i < books.size(); i++) {
		string info = books[i].getBookInfo();
		cout << "------- " << i + 1 << " -------";
		cout << info << endl;
	}
}

void BookingUserInterface::bookingTheBook(BookDatabase& DB, BookBooker& bookBooker, int bookNumber, Client* client)
{
	bookBooker.bookTheBook(DB, (&DB.getAllBooks()[bookNumber]), client);
}