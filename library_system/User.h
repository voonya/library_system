#pragma once
#include "ClientProfileInterface.h"
#include "BookCatalogueUI.h"
#include "BookingUserMenu.h"
#include "ClientCatalogueUI.h"
#include "ClientDatabaseOutputter.h"

using namespace std;

class User
{
	Client* client;
	BookDatabase* DB;
	ClientDatabase* DB_C;
	void show_book(BookDatabase* DB);
	void show_info();
	void booking_menu();
	void show_clients();
	void registration(ClientDatabase* DB_C);
public:
	User(Client* client) : client(client) {};
	void start_menu(BookDatabase* DB, ClientDatabase* DB_C);
};

