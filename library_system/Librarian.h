#pragma once
#include "Client_header.h"
#include "ClientProfileInterface.h"
#include <string>
using namespace std;
class Librarian
{
	string name;
	string surname;
	string phone_number;
	string address;
	string login;
	string password;
	ClientDatabase* DB_C;
	BookDatabase* DB;
	void register_client();
	void edit_client();
	void interact_book();
	void show_clients();
	void show_book();
public:
	Librarian(string name, string surname, string phone, string login, string password);
	void start_menu(ClientDatabase* DB, BookDatabase* DB_B);
	friend string get_more_info(Librarian c);
	friend class LibrarianDatabase;
	friend bool sorting_func_name_l(Librarian a, Librarian b);
	friend bool sorting_func_surname_l(Librarian a, Librarian b);
	friend class LoginForm;
};

