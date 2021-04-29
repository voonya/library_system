#pragma once
#include "../../Book/Book.h"
#include "../../Databases/BookDatabase.h"
#include "../../Databases/ClientDatabase.h"
#include "../../Book/BookBooker.h"

class BookingUserMenu {
public:
	friend class Client;
	void startDialogMenu(BookDatabase& DB, BookBooker& bookBooker, ClientDatabase& cDB);
	void showBookingsMenuUser(BookDatabase* DB, BookBooker& bookBooker, Client* client);
	void showBooks(BookDatabase& DB);
	void showBookings(BookDatabase& DB);
	void bookingTheBook(BookDatabase& DB, BookBooker& bookBooker, int bookNumber, Client* client);
	void takingTheBook(BookDatabase& DB, BookBooker& bookBooker, int bookNumber, Client* client);
};