#include "ClientRegestrationInterface.h"
#include "ClientProfileInterface.h"
#include "BookCatalogueUI.h"
#include "ClientCatalogueUI.h"
#include <iostream>

#include "ClientDatabase.h"


int main()
{
	ClientRegestrationInterface clientRegistrationMenu;
	ClientProfileInterface clientProfileMenu;
	
	vector<Client> clientVector;
	ClientDatabase DB_Clients(clientVector);
	DB_Clients.fake_init();
	ClientCatalogueUI client_ui(&DB_Clients);
	
	vector<Book> bookVector;
	BookDatabase book_database(bookVector);
	book_database.fake_init();
	book_catalogue_ui book_catalogue_ui(&book_database);
	
	bool running = true;
	while (running)
	{
		cout << "Choose a menu:" << endl <<
			"1 - register a client" << endl <<
			"2 - edit a client profile" << endl <<
			"3 - open the book catalogue" << endl <<
			"4 - open the client catalogue" << endl <<
			"5 - quit the app" << endl;
		int choice;
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			clientRegistrationMenu.start_menu(DB_Clients.getAllClients());
			break;
		}
		case 2:
		{
			clientProfileMenu.start_menu(DB_Clients.getAllClients());
			break;
		}
		case 3:
		{
			book_catalogue_ui.output_menu();
			break;
		}
		case 4:
		{
			client_ui.output_menu();
			break;
		}
		case 5:
		{
			running = false;
			break;
		}
		}
	}
	return 0;
}

