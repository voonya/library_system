#pragma once
#include "ClientProfileInterface.h"
#include "BookCatalogueUI.h"

using namespace std;

class User
{
	Client* client;
	void show_book(BookDatabase* DB);
	void show_info();
public:
	User(Client* client) : client(client) {};
	void start_menu(BookDatabase* DB);
};

