#pragma once
#include "ClientProfileInterface.h"
#include "BookCatalogueUI.h"

using namespace std;

class User
{
	Client* client;
public:
	User(Client* client) : client(client) {};
	void show_book(BookDatabase* DB);
	void show_info();
};

