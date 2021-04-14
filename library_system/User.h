#pragma once
#include "ClientProfileInterface.h"
#include "BookCatalogueUI.h"
#include "BookingUserMenu.h"

using namespace std;

class User
{
	Client* client;
	void show_book(BookDatabase* DB);
	void show_info();
	void booking_menu(BookDatabase DB, BookBooker booker);
public:
	User(Client* client) : client(client) {};
	void start_menu(BookDatabase DB);
};

