#pragma once
#include "../Menus/Client/ClientProfileInterface.h"
#include "../Menus/Book/BookCatalogueUI.h"
#include "../Menus/Book/BookingUserMenu.h"
#include "../Menus/Client/ClientCatalogueUI.h"
#include "../Menus/Client/ClientDatabaseOutputter.h"
#include "../Menus/Client/ClientRegestrationInterface.h"

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
public:
	User(Client* client) : client(client) {};
	void start_menu(BookDatabase* DB, ClientDatabase* DB_C);
	void registration(ClientDatabase* DB_C);
};

