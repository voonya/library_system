#include "User.h"
void User::show_book(BookDatabase* DB) {
	book_catalogue_ui menu(DB);
	menu.output_menu();
}

void User::show_info() {
	ClientProfileInterface menu;
	menu.show_info(*client);
}
void User::start_menu(BookDatabase* DB) {
	bool running = true;
	while (running)
	{
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
			break;
		}
		case 2:
		{
			show_book(DB);
			break;
		}
		case 3:
		{
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