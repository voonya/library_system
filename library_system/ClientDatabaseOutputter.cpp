#include "ClientDatabaseOutputter.h"

#include <iostream>

ClientDatabaseOutputter::ClientDatabaseOutputter(ClientDatabase* database)
{
	this->database = database;
}

void ClientDatabaseOutputter::output_client_database()
{
	cout << "Client catalogue:" << endl;
	for (Client client : database->getAllClients())
	{
		cout << request_client_info(client);
	}
}

string ClientDatabaseOutputter::request_client_info(Client client)
{
	return get_main_info(client) + "\n------------" + "\n";
}
