#include "ClientProfileCreator.h"
#include <iostream>
void ClientProfileCreator::add_new_client(vector<Client>& DB) {
	bool flag = false;
	for (int i = 0; i < DB.size(); i++) {
		if (DB[i].name == client.name && DB[i].surname == client.surname && DB[i].phone_number == client.phone_number) {
			flag = true;
			cout << "\n Database already has a client with theese name and surname:\n";
			cout << get_main_info(DB[i]) << get_more_info(DB[i]);
			cout << "\n Do you want to add this new client still? (y/n)";
			string answer;
			getline(cin, answer);
			
			if (answer == "y") {
				DB.push_back(client);
				cout << "\n Adding new client was done\n";
				cout << "\n------------------------------------------------------------------------------\n";
			}
			else if (answer == "n") { 
				cout << "\n Adding new client was denied\n";
				cout << "------------------------------------------------------------------------------\n";
			}
			else { 
				"\n Incorrect answer\n Try again: ";
				getline(cin, answer);
			}
			break;
		}
	}
	if (!flag) {
		DB.push_back(client);
		cout << "\n Adding new client was done\n";
		cout << "\n------------------------------------------------------------------------------\n";
	}
}