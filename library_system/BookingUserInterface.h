#pragma once
#include "Book.h"
#include "BookDatabase.h"
#include "BookBooker.h"

class BookingUserInterface {
public:
	void startDialogMenu(BookDatabase& DB, BookBooker& bookBooker, Client* client);
	void showBooks(BookDatabase& DB);
	void bookingTheBook(BookDatabase& DB, BookBooker& bookBooker, int bookNumber, Client* client);
};