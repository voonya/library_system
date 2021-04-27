#define _CRT_SECURE_NO_WARNINGS
#include "ClientRegestrationInterface.h"
#include <iostream>


void ClientRegestrationInterface::set_info(ClientDatabase* DB) {
	string a;
	cout << "\n---------------------------------------------------------------------------------\n";
	cout << "\n Nice. To create a new client`s profile you need to input some info about client\n";
	cout << "\n---------------------------------------------------------------------------------\n";
	cout << " Login: ";
	getline(cin, a);
	while (!(DB->checkLogin(a))) {
		cout << " This login is taken\n Try again";
		cout << " Login: ";
		getline(cin, a);
	}
	client.set_login(a);
	cout << " Password: ";
	getline(cin, a);
	while (!(DB->checkPass(a))) {
		cout << " This password is taken\n Try again";
		cout << " Password: ";
		getline(cin, a);
	}
	client.set_password(a);
	cout << " Name: ";
	getline(cin, a);
	client.set_name(a);
	cout << " Surname: ";
	getline(cin, a);
	client.set_surname(a);
	//setting a date of birth of client

	vector<int> date;
	bool flag = false;
	while (!flag) {
		date.clear();
		char line[150];
		cout << " Date of birth (in format 1.1.2000): ";
		cin.getline(line, 150);
		date = client.convert_to_date(line);
		if (date.size() != 3) {
			flag = false;
			cout << " Incorrect type. Try again.\n";
		}
		else {
			flag = true;
		}
	}
	client.set_date_birth(date[0], date[1], date[2]);
	
	// setting phone number
	cout << " Phonenumber: ";
	getline(cin, a);
	client.set_phone_number(a);
	// setting address
	cout << " Address: ";
	getline(cin, a);
	client.set_address(a);
}

void ClientRegestrationInterface::start_menu(ClientDatabase* DB) {
	cout << "\n---------------------------------------------------------------------------------\n";
	cout << "\n Hello! You are now in creating client menu.\n If you want to create new profile enter 's'\n If you want to quit enter 'q'\n ";
	string answer;
	cin.ignore(1);
	getline(cin, answer);
	work_loop(answer, DB);
}



void ClientRegestrationInterface::work_loop(string& answer, ClientDatabase* DB) {
	while (answer != "q") {
		system("cls");
		if (answer == "s") {
			set_info(DB);
			system("cls");
			cout << "\n---------------------------------------------------------------------------------\n";
			cout << "\n Finally we got:\n";
			cout << get_main_info(client.get_client()) << "\n" << get_more_info(client.get_client());
			cout << "\n---------------------------------------------------------------------------------\n";
			cout << " \n Everything is correct? (y/n): ";
			getline(cin, answer);
			cout << "\n---------------------------------------------------------------------------------\n";
			if (answer == "y") {
				int index = DB->findByNameAndSurnameAndPhone(client.get_name(), client.get_surname(), client.get_phone());
				if (index == -1) {
					DB->addClientToDatabase(client.get_client());
					cout << "\n Adding new client was done\n";
					cout << "\n---------------------------------------------------------------------------------\n";
				}
				else {
					system("cls");
					cout << "\n Database already has a client with theese name, surname and phonenumber:\n";
					cout << get_main_info((*(DB->getAllClients()))[index]) << get_more_info((*(DB->getAllClients()))[index]);
					cout << "\n---------------------------------------------------------------------------------\n";
					cout << "\n Do you want to add this new client still? (y/n): ";
					string answer;
					getline(cin, answer);

					if (answer == "y") {
						DB->addClientToDatabase(client.get_client());
						cout << "\n Adding new client was done\n";
						cout << "\n---------------------------------------------------------------------------------\n";
					}
					else if (answer == "n") {
						cout << "\n Adding new client was denied\n";
						cout << "\n---------------------------------------------------------------------------------\n";
					}
				}
				cout << "\n Do you want to add one more client?\n Enter 's' to go on and 'q' to quit:\n ";
				getline(cin, answer);
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