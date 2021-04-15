#pragma once
#include "Book.h"
#include "BookDatabase.h"
#include "ClientDatabase.h"
#include "BookBooker.h"

class BookingUserMenu {
public:
	void startDialogMenu(BookDatabase& DB, BookBooker& bookBooker, ClientDatabase& cDB);
	void showBookingsMenuUser(BookDatabase* DB, BookBooker& bookBooker, Client* client);
	void showBooks(BookDatabase& DB);
	void showBookings(BookDatabase& DB);
	void bookingTheBook(BookDatabase& DB, BookBooker& bookBooker, int bookNumber, Client* client);
	void takingTheBook(BookDatabase& DB, BookBooker& bookBooker, int bookNumber, Client* client);
};