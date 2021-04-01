#include "ClientCatalogueUI.h"
#include "ClientDatabaseOutputter.h"
#include <iostream>
#include <algorithm>

using namespace std;
void ClientCatalogueUI::output_client_catalogue()
{
	cout << "Client catalogue:" << endl;
	ClientDatabaseOutputter outputter(client_catalogue);
	outputter.output_client_database();
}

ClientCatalogueUI::ClientCatalogueUI(ClientDatabase* database)
{
	client_catalogue = database;
}

// returns false, when the menu is quit
bool ClientCatalogueUI::output_menu()
{
	cout << "Enter 1 to output the catalogue" << endl;
	cout << "Enter 2 to output the catalogue processing form" << endl;
	cout << "Enter 3 to quit this menu" << endl;
	int choice;
	cin >> choice;
	switch (choice)
	{
	case 1:
		output_client_catalogue();
		return output_menu();
	case 2:
		output_catalogue_processing_form();
		return output_menu();
	case 3:
		return false;
	default:
		cout << "Unknown choice!" << endl;
		return output_menu();
	}


}



void ClientCatalogueUI::output_catalogue_processing_form()
{
	cout << "Choose sorting parameter (1 - name, 2 - surname): ";
	int choice;
	cin >> choice;
	vector<Client> sorted;
	switch (choice)
	{
	case 1:
		sorted = client_catalogue->sort_by_name();
		ClientDatabaseOutputter outputter1(new ClientDatabase(sorted));
		cout << "Catalogue sorted!" << endl;
		outputter1.output_client_database();
		break;
	case 2:
		sorted = client_catalogue->sort_by_surname();
		ClientDatabaseOutputter outputter2(new ClientDatabase(sorted));
		cout << "Catalogue sorted!" << endl;
		outputter2.output_client_database();
		break;
	default:
		cout << "Unknown parameter" << endl;
	}
	output_menu();
}