#include "User.h"
void User::show_book(BookDatabase* DB) {
	book_catalogue_ui menu(DB);
	menu.output_menu();
}

void User::show_info() {
	ClientProfileInterface menu;
	menu.show_info(*client);
}