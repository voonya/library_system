#pragma once
#include "Book.h"
#include "BookDatabase.h"
#include "BookBooker.h"

class BookingUserMenu {
public:
	friend Client;
	void startDialogMenu(BookDatabase& DB, BookBooker& bookBooker, Client* client);
	void showBooks(BookDatabase& DB);
	friend void bookingTheBook(BookDatabase& DB, BookBooker& bookBooker, int bookNumber, Client* client);
};