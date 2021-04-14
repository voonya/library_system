#include "Librarian.h"
#include <string>
using namespace std;

Librarian::Librarian(string name, string surname, string phone)
{
	this->name = name;
	this->surname = surname;
	this->phone_number = phone;
}

string get_more_info(Librarian c) {
	string info = " Phonenumber: " + c.phone_number;
	return info;
}

//string get_main_info(Client c) {
//	string info = " Name: " + c.name + "\n Surname: " + c.surname;
//	return info;
//}
