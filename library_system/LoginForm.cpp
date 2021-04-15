#include "LoginForm.h"

#include <iostream>
#include <string>

#include "Client_header.h"
using namespace std;
int LoginForm::askUserType()
{
	while (true)
	{
		cout << "Are you a client or a librarian (1 - client, 2 - librarian):" << endl;
		int answer;
		cin >> answer;
		switch (answer)
		{
		case 1:
			return 1;
		case 2:
			return 2;
		default:
			cout << "Incorrect answer! Try again" << endl;
		}
	}
}

int LoginForm::getUserIndex(ClientDatabase& DB, bool& found)
{
	while (true)
	{
		string name, surname, password;
		cin.ignore();
		cout << " Enter name: ";
		getline(cin, name);
		cout << " Enter surname: ";
		getline(cin, surname);
		cout << " Enter password: ";
		getline(cin, password);
		vector<Client> clients = *(DB.getAllClients());
		for (int i = 0; i < clients.size(); i++) {
			if (clients[i].name == name && clients[i].surname == surname && clients[i].password == password) {
				found = true;
				return i;
			}
		}
		cout << "\n---------------------------------------------------------------------------------\n";
		cout << " There is no client with this data in db\n";
		cout << "\n---------------------------------------------------------------------------------\n";
		cout << "\n Do you want to try again or change profile type (1/2): ";
		int answer;
		cin >> answer;
		switch (answer)
		{
		case 1:
			continue;
		default:
			found = false;
			return -1;
		}
	}
}
