#include "ClientDatabaseOutputter.h"
#include <iomanip>
#include <iostream>

ClientDatabaseOutputter::ClientDatabaseOutputter(ClientDatabase* database)
{
	this->database = database;
}

void ClientDatabaseOutputter::output_client_database()
{
	cout << "Client catalogue:" << endl;
	cout << setw(13) << "Name | " << setw(18) << "Surname | " << setw(14) << "Date | " << setw(33) << "Address | " << setw(33) << "Login | " << setw(31)
		<< "Password\n";
	cout << "---------------------------------------------------------------------------------------------------------------------------------------------\n";
	for (Client client : *(database->getAllClients()))
	{
		vector<string> info = get_info_table(client);
		cout << setw(10) << info [0] << " | " << setw(15) << info[1] << " | " << setw(11) << info[2] << " | " << setw(30) << info[3] 
			<< " | " << setw(30) << info[4] << " | " << setw(30)
			<< info[5] << endl ;
		cout << "---------------------------------------------------------------------------------------------------------------------------------------------\n";
		//cout << request_client_info(client);
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