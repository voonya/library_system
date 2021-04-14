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
void Librarian::register_client(ClientDatabase* DB) {
	ClientRegestrationInterface menu;
	menu.start_menu(DB);
}
void Librarian::edit_client(ClientDatabase* DB) {
	ClientProfileInterface menu;
	menu.start_menu(DB->getAllClients());
}
void Librarian::show_book(BookDatabase* DB) {
	book_catalogue_ui menu(DB);
	menu.output_menu();
}
void Librarian::interact_book(BookDatabase* DB, ClientDatabase* DB_C) {
	BookingUserMenu booking;
	BookBooker booker;
	booking.startDialogMenu(*DB, booker, *DB_C);
}
void Librarian::show_clients(ClientDatabase* DB) {
	ClientCatalogueUI client_ui(DB);
	client_ui.output_menu();
}
/*
string get_main_info(Client c) {
	string info = " Name: " + c.name + "\n Surname: " + c.surname;
	return info;
}
void register_client();
	void edit_client();
	void interact_book();
	void show_clients();
	
*/