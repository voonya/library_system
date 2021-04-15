#include <iostream>
#include "BookingUserMenu.h"


int chooseBook(int count) {
	cout << " To choose some book for booking enter book number: ";
	int bookNumber = -1;
	cin >> bookNumber;
	while (bookNumber > count || bookNumber <= 0) {
		cout << " Incorrect number, try again: ";
		cin >> bookNumber;
	}
	return bookNumber;
}

vector<Client*> choose_client(ClientDatabase& clientDB)
{
	string name;
	cout << " Name: ";
	cin.ignore();
	getline(cin, name);
	string surname;
	cout << " Surname: ";
	getline(cin, surname);
	vector<Client*> clients = clientDB.findByNameAndSurname(name, surname);
	return clients;
}

void BookingUserMenu::showBookingsMenuUser(BookDatabase* DB, BookBooker& bookBooker, Client* client)
{
	int choice = 0;
	cout << "It's menu of booking books\n";
	while (choice != 3) {
		cout << "1 - to see the bookings for a book\n";
		cout << "2 - to book or take a book\n";
		cout << "3 - to quit\n";
		cout << "Enter your answer: ";
		cin >> choice;
		if (choice == 1)
		{
			showBookings(*DB);
		}
		else if (choice == 2) {
			int number = 0;
			cout << "1 - to view books\n";
			cout << "2 - to exit from menu\n";
			cout << "Enter your answer: ";
			cin >> number;
			if (number == 1) {
				showBooks(*DB);
				cout << "1 - to choose book for booking or taking\n";
				cout << "2 - to exit from menu\n";
				cout << "Enter your answer: ";
				cin >> number;
				if (number == 2)
					return;
				int bookNumber = chooseBook(DB->getAllBooks().size());
				cout << "Your chosen book is: " << bookNumber << endl;
				cout << "1 - to book the chosen book\n";
				cout << "2 - to take the chosen book\n";
				cout << "3 - to exit from booking interface\n";
				cout << "Enter your answer: ";
				cin >> number;
				if (number == 1) {
					bookingTheBook(*DB, bookBooker, bookNumber - 1, client);
					cout << "You successfully booked the book!!!\n";
				}
				if (number == 2) {
					takingTheBook(*DB, bookBooker, bookNumber - 1, client);
				}
			}
		}
		else
		{
			return;
		}
	}
}

void BookingUserMenu::startDialogMenu(BookDatabase& DB, BookBooker& bookBooker, ClientDatabase& cDB)
{
	int choice = 0;
	cout << "It's menu of booking books\n";
	while (choice != 3) {
		cout << "1 - to see the bookings for a book\n";
		cout << "2 - to book or take a book\n";
		cout << "3 - to quit\n";
		cout << "Enter your answer: ";
		cin >> choice;
		if (choice == 1)
		{
			showBookings(DB);
		}
		else if (choice == 2) {
			cout << "1 - choose a client before choosing the book to book or take\n";
			cout << "2 - to quit\n";
			cout << "Enter you answer: ";
			int answer;
			cin >> answer;
			Client* chosen;
			if (answer == 1)
			{
				vector<Client*> clients = choose_client(cDB);
				if (clients.empty())
				{
					cout << "No clients found!" << endl;
					cout << "Try again (1 - yes, 2 - no)?" << endl;
					int choice;
					cin >> choice;
					if (choice == 1)
					{
						startDialogMenu(DB, bookBooker, cDB);
					}
					return;
				}
				else if (clients.size() > 1)
				{
					cout << "There are several such clients! Choose one (enter the order of the client starting from 1)" << endl;
					for (Client* client_it : clients)
					{
						cout << get_main_info(*client_it) + "\n------------" + "\n";
					}
					int order;
					cin >> order;
					chosen = clients[order];
				}
				else
				{
					chosen = clients[0];
				}
			}
			else
			{
				return;
			}

			int number = 0;
			cout << "1 - to view books\n";
			cout << "2 - to exit from menu\n";
			cout << "Enter your answer: ";
			cin >> number;
			if (number == 1) {
				showBooks(DB);
				cout << "1 - to choose book for booking\n";
				cout << "2 - to exit from menu\n";
				cout << "Enter your answer: ";
				cin >> number;
				if (number == 2)
					return;
				int bookNumber = chooseBook(DB.getAllBooks().size());
				cout << "Your chosen book is: " << bookNumber << endl;
				cout << "1 - to book the chosen book\n";
				cout << "2 - to take the chosen book\n";
				cout << "3 - to exit from booking interface\n";
				cout << "Enter your answer: ";
				cin >> number;
				if (number == 1) {
					bookingTheBook(DB, bookBooker, bookNumber - 1, chosen);
					cout << "You successfully booked the book!!!\n";
				}
				if (number == 2) {
					takingTheBook(DB, bookBooker, bookNumber - 1, chosen);
				}
			}
		}
		else
		{
			return;
		}
	}
}

void BookingUserMenu::showBooks(BookDatabase& DB)
{
	vector< Book > books = DB.getAllBooks();
	for (int i = 0; i < books.size(); i++) {
		string info = books[i].getBookInfo();
		cout << "------- " << i + 1 << " -------" << endl;
		cout << info << endl;
	}
}

void BookingUserMenu::showBookings(BookDatabase& DB)
{
	cout << "Select a book:" << endl;
	showBooks(DB);
	int bookNumber = chooseBook(DB.getAllBooks().size());
	cout << "Your choosen book is: " << bookNumber << endl;
	cout << "The bookings for the book are:" << endl;
	Book book = DB.getAllBooks()[bookNumber - 1];
		auto booking_queue = book.getBookingQueue();
		int number = 0;
		while (!booking_queue.empty())
		{
			number++;
			Booking booking = booking_queue.front();
			booking_queue.pop();
			cout << number << ": booked by\n " << get_main_info(*booking.client) << endl ;
		}
}

void BookingUserMenu::bookingTheBook(BookDatabase& DB, BookBooker& bookBooker, int bookNumber, Client* client)
{
	Book* book = &((*(DB.getAllBooksPointer()))[bookNumber]);
	bookBooker.bookTheBook(DB, book, client);
}

void BookingUserMenu::takingTheBook(BookDatabase& DB, BookBooker& bookBooker, int bookNumber, Client* client)
{
	Book* book = &((*(DB.getAllBooksPointer()))[bookNumber]);
	bookBooker.takeTheBook(DB, book, client);
}
