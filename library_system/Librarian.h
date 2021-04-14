#pragma once
#include <string>

#include "Client_header.h"

using namespace std;
class Librarian
{
	string name;
	string surname;
	string phone_number;
public:
	Librarian(string name, string surname, string phone);
	friend string get_more_info(Librarian c);
};

