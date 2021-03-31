#include "Interface_NewClient.h"
#include <iostream>


void Interface_NewClient::set_info() {
	string a;
	cout << " Nice. To create a new clien`s profile you need to input some info about client\n";
	cout << " Name: ";
	getline(cin, a);
	client.set_name(a);
	cout << " Surname: ";
	getline(cin, a);
	client.set_surname(a);
	//setting a date of birth of client
	cout << " Date of birth (in format 1.1.2000): ";
	getline(cin, a);
	int d, m, y;
	d = stoi(a.substr(0, a.find("."))); // day
	a.erase(0, a.find(".") + 1);
	m = stoi(a.substr(0, a.find("."))); // month
	a.erase(0, a.find(".") + 1);
	y = stoi(a); // year
	client.set_date_birth(d, m, y);
	// setting phone number
	cout << " Phonenumber: ";
	getline(cin, a);
	client.set_phone_number(a);
	// setting address
	cout << " Address: ";
	getline(cin, a);
	client.set_address(a);
}

void Interface_NewClient::start_menu(vector<Client>& DB) {
	cout << " Hello! You are now in creating client menu.\n If you want to create new profile enter 's'\n If you want to quit enter 'q'\n";
	string answer;
	getline(cin, answer);
	work_loop(answer, DB);
}



void Interface_NewClient::work_loop(string& answer, vector<Client>& DB) {
	while (answer != "q") {
		if (answer == "s") {
			set_info();
			cout << "\n Finally we got:\n";
			cout << get_main_info(client.get_client()) << "\n" << get_more_info(client.get_client());
			cout << " Everything is correct? (y/n): ";
			getline(cin, answer);
			if (answer == "y") {
				client.add_new_client(DB);
				answer = "q";
			}
			else {
				cout << " Okey. Lets try again\n";
				answer = "s";
			}
		}
		else {
			cout << " Incorrect answer. Lets try again:\n";
			getline(cin, answer);
		}
	}
}