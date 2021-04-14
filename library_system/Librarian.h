#pragma once
#include "Client_header.h"
#include <string>
using namespace std;
class Librarian
{
	string name;
	string surname;
	string phone_number;
public:
	Librarian(string name, string surname, string phone);
	friend string get_more_info(Librarian c);
	friend class LibrarianDatabase;
	friend bool sorting_func_name_l(Librarian a, Librarian b);
	friend bool sorting_func_surname_l(Librarian a, Librarian b);
};

