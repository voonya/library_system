#pragma once
#include "Client_header.h"
#include "ClientDatabase.h"
#include "ClientRegestrationInterface.h"
#include "ClientProfileInterface.h"
#include "BookCatalogueUI.h"
#include "ClientCatalogueUI.h"
#include "BookingUserMenu.h"
#include <string>
using namespace std;
class Librarian
{
	string name;
	string surname;
	string phone_number;
public:
	Librarian(string name, string surname, string phone);
	void register_client(ClientDatabase* DB);
	void edit_client(ClientDatabase* DB);
	void interact_book(BookDatabase* DB,ClientDatabase* DB_C);
	void show_clients(ClientDatabase* DB);
	void show_book(BookDatabase* DB);
	friend string get_more_info(Librarian c);
	friend class LibrarianDatabase;
	friend bool sorting_func_name_l(Librarian a, Librarian b);
	friend bool sorting_func_surname_l(Librarian a, Librarian b);
};

