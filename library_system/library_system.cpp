
#include "Librarian.h"
#include "User.h"

int main()
{
	/*
	ClientRegestrationInterface clientRegistrationMenu;
	ClientProfileInterface clientProfileMenu;
	*/
	vector<Client> clientVector;
	ClientDatabase DB_Clients(clientVector);
	DB_Clients.fake_init();
	//ClientCatalogueUI client_ui(&DB_Clients);
	
	vector<Book> bookVector;
	BookDatabase book_database(bookVector);
	book_database.fake_init();
	//book_catalogue_ui book_catalogue_ui(&book_database);

	//BookingUserMenu booking;
	Librarian lib("Name","Name", "Phone"); 
	User user(&(*DB_Clients.getAllClients())[1]);
	//lib.start_menu(&DB_Clients, &book_database);
	user.start_menu(&book_database,&DB_Clients);
	return 0;
}
/*
bool running = true;
while (running)
{
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
		//lib.register_client(&DB_Clients);
		//user.show_info();
		
		clientRegistrationMenu.start_menu(&DB_Clients);
		break;
	}
	case 2:
	{
		//lib.edit_client(&DB_Clients);
		
		clientProfileMenu.start_menu(DB_Clients.getAllClients());
		break;
	}
	case 3:
	{
		//user.show_book(&book_database);
		//lib.show_book(&book_database);
		
		book_catalogue_ui.output_menu();
		break;
	}
	case 4:
	{
		lib.show_clients(&DB_Clients);
		
		client_ui.output_menu();
		break;
	}
	case 5:
	{
		lib.interact_book(&book_database, &DB_Clients);
		
		BookBooker booker;
		booking.startDialogMenu(book_database, booker, DB_Clients);
		break;
	}
	case 6:
	{

		running = false;
		break;
	}
	}
}*/