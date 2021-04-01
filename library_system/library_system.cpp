#include "ClientRegestrationInterface.h"
#include "ClientProfileInterface.h"
#include <iostream>

#include "ClientDatabase.h"


int main()
{
	ClientRegestrationInterface clientRegistrationMenu;
	ClientProfileInterface clientProfileMenu;
	vector<Client> clientVector;
	ClientDatabase DB_Clients(clientVector);
	bool running = true;
	while (running)
	{
		cout << "Choose a menu:" << endl <<
			"1 - register a client," << endl <<
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
			break;
		}
		case 4:
		{
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

