#pragma once
#include "Book.h"
#include "BookDatabase.h"
#include "ClientDatabase.h"
#include "BookBooker.h"

class BookingUserMenu {
public:
	void startDialogMenu(BookDatabase& DB, BookBooker& bookBooker, ClientDatabase& cDB);
<<<<<<< HEAD
	void showBookingsMenuUser(BookDatabase& DB, BookBooker& bookBooker, ClientDatabase& cDB, Client* client);
=======
	void showBookingsMenuUser(BookDatabase& DB, BookBooker& bookBooker, Client* client);
>>>>>>> 2f35ff9cdb69ca68e7413f9e22b09456b17411b4
	void showBooks(BookDatabase& DB);
	void showBookings(BookDatabase& DB);
	void bookingTheBook(BookDatabase& DB, BookBooker& bookBooker, int bookNumber, Client* client);
	void takingTheBook(BookDatabase& DB, BookBooker& bookBooker, int bookNumber, Client* client);
};