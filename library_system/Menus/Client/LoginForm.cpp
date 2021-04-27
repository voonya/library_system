#include "LoginForm.h"

#include <iostream>
#include <string>

#include "../../Client/Client_header.h"
using namespace std;
int LoginForm::askUserType()
{
	while (true)
	{
		system("cls");
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
		string login, password;
		cin.ignore();
		cout << " Enter login: ";
		getline(cin, login);
		cout << " Enter password: ";
		getline(cin, password);
		vector<Client> clients = *(DB.getAllClients());
		for (int i = 0; i < clients.size(); i++) {
			if (clients[i].login == login && clients[i].password == password) {
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

int LoginForm::getLibrarianIndex(LibrarianDatabase librarian_database, bool& found)
{
	while (true)
	{
		system("cls");
		string login, password;
		cin.ignore();
		cout << " Enter login: ";
		getline(cin, login);
		cout << " Enter password: ";
		getline(cin, password);
		vector<Librarian> librarians = *(librarian_database.getAllLibrarians());
		for (int i = 0; i < librarians.size(); i++) {
			if (librarians[i].login == login && librarians[i].password == password) {
				found = true;
				return i;
			}
		}
		cout << "\n---------------------------------------------------------------------------------\n";
		cout << " There is no librarians with this data in db\n";
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
