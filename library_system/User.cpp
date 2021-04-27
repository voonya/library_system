#include "User.h"
void User::show_book(BookDatabase* DB) {
	book_catalogue_ui menu(DB);
	menu.output_menu();
}

void User::show_info() {
	ClientDatabaseOutputter menu(DB_C);
	menu.output_client(*client);
}
void User::booking_menu() {
	BookingUserMenu menu;
	BookBooker booker;
	menu.showBookingsMenuUser(DB, booker, client);
}
void User::show_clients() {
	ClientCatalogueUI client_ui(DB_C);
	client_ui.output_menu();
}
void User::registration(ClientDatabase* DB_C) {
	ClientRegestrationInterface menu;
	menu.start_menu(DB_C);
}
void User::start_menu(BookDatabase* DB_B, ClientDatabase* DB_Cl) {
	DB = DB_B;
	DB_C = DB_Cl;
	bool running = true;
	while (running)
	{
		system("cls");
		cout << "Choose a menu:" << endl <<
			"1 - look your profile" << endl <<
			"2 - look book catalogue" << endl <<
			"3 - take a book" << endl <<
			"4 - quit the app" << endl;
		int choice;
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			show_info();
			system("pause");
			break;
		}
		case 2:
		{
		
			show_book(DB);
			break;
		}
		case 3:
		{
			
			booking_menu();
			break;
			/*
			show_book(DB_B);
			break;*/
		}
		case 4:
		{
			running = false;
			break;
		}
		}
	}
}