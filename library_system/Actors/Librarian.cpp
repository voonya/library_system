#include "Librarian.h"
#include <string>


#include "../Menus/Book/BookCatalogueUI.h"
#include "../Menus/Book/BookingUserMenu.h"
#include "../Menus/Client/ClientCatalogueUI.h"
#include "../Menus/Client/ClientRegestrationInterface.h"
using namespace std;

Librarian::Librarian(string name, string surname, string phone, string login, string password)
{
	this->name = name;
	this->surname = surname;
	this->phone_number = phone;
	this->login = login;
	this->password = password;
}

string get_more_info(Librarian c) {
	string info = " Phonenumber: " + c.phone_number;
	return info;
}
void Librarian::register_client() {
	system("cls");
	ClientRegestrationInterface menu;
	menu.start_menu(DB_C);
}
void Librarian::edit_client() {
	system("cls");
	ClientProfileInterface menu;
	menu.start_menu(DB_C->getAllClients());
}
void Librarian::show_book() {
	book_catalogue_ui menu(DB);
	menu.output_menu();
}
void Librarian::interact_book() {
	BookingUserMenu booking;
	BookBooker booker;
	booking.startDialogMenu(*DB, booker, *DB_C);
}
void Librarian::show_clients() {
	ClientCatalogueUI client_ui(DB_C);
	client_ui.output_menu();
}
void Librarian::start_menu(ClientDatabase* DB_Cl, BookDatabase* DB_B) {
	DB = DB_B;
	DB_C = DB_Cl;
	bool running = true;
	while (running)
	{
		system("cls");
		cout << "Choose a menu:" << endl <<
			"1 - register a client" << endl <<
			"2 - edit a client profile" << endl <<
			"3 - open the book catalogue" << endl <<
			"4 - open the client catalogue" << endl <<
			"5 - open the menu to book or take the book" << endl <<
			"6 - quit the app" << endl;
		int choice;
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			register_client();
			break;
		}
		case 2:
		{
			edit_client();
			break;
		}
		case 3:
		{
			show_book();
			break;
		}
		case 4:
		{
			show_clients();
			break;
		}
		case 5:
		{
			interact_book();
			break;
		}
		case 6:
		{
			running = false;
			break;
		}
		default: {
			running = false;
			break;
		}
		}
	}
}
