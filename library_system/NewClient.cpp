#include "NewClient.h"
#include <iostream>

string get_more_info(Client c) {
	string info = " Phonenumber: " + c.phone_number + "\n Address: " + c.address + "\n";
	return info;
}

string get_main_info(Client c) {
	string info = " Surname: " + c.surname + "\n Name: " + c.name;
	string date = "\n Date of birth: " + c.date_of_birth.get_date();
	return info + date;
}


string NewClient::add_new_client(vector<Client> DB) {
	bool flag = false;
	for (int i = 0; i < DB.size(); i++) {
		if (DB[i].name == client.name && DB[i].surname == client.surname) {
			flag = true;
			cout << " Database already has a client with theese name and surname:\n";
			cout << get_main_info(DB[i]) << get_more_info(DB[i]);
			cout << " Do you want to add this new client still? (y/n)";
			string answer;
			getline(cin, answer);
			while (answer != "y" or answer != "n") {
				if (answer == "y") {
					DB.push_back(client);
					cout << "Adding new client was done\n";
				}
				else if (answer == "n") { cout << "Adding new client was denied\n"; }
				else { 
					" Incorrect answer\n Try again: ";
					getline(cin, answer);
				};
			}
			break;
		}
	}
	if (!flag) {
		DB.push_back(client);
		cout << "Adding new client was done\n";
	}
}