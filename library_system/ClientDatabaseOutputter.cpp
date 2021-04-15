#include "ClientDatabaseOutputter.h"

#include <iostream>

ClientDatabaseOutputter::ClientDatabaseOutputter(ClientDatabase* database)
{
	this->database = database;
}

void ClientDatabaseOutputter::output_client_database()
{
	cout << "Client catalogue:" << endl;
	for (Client client : *(database->getAllClients()))
	{
		cout << request_client_info(client);
	}
}
void ClientDatabaseOutputter::output_client(Client client)
{
	cout << request_client_info(client) << "\n";
}

string ClientDatabaseOutputter::request_client_info(Client client)
{
	string str = get_main_info(client) + "\n" + get_more_info(client);
	str += "\n Debts: " + get_debts_info(client) + "\n Reservation: " + get_reservation_info(client) + "\n History: " + get_history_info(client);
	return str + "\n------------\n";
}