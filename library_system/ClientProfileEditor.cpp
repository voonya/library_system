#include "ClientProfileEditor.h"



Client ClientProfileEditor::find_client(vector<Client> DB, string name, string surname, string phonenumber) {
	Client client;
	index_in_db = -1;
	for (int i = 0; i < DB.size(); i++) {
		if (DB[i].name == name && DB[i].surname == surname && DB[i].phone_number == phonenumber) {
			client = DB[i];
			index_in_db = i;
			return client;
		}
	}
	client.name = "0";
	return client;
}
void ClientProfileEditor::update_info(Client client, vector<Client>& DB) {
	DB[index_in_db] = client;
}

void ClientProfileEditor::change_history(string type, string changes) {
	if (type == "d") {
		cout << stoi(changes);
		client.history.erase(client.history.begin() + stoi(changes) - 1);
	}
	else if (type == "a") {
		client.history.push_back(changes);
	}
}

void ClientProfileEditor::change_debts(string type, string changes) {
	if (type == "d") {
		client.debts.erase(client.debts.begin() + stoi(changes) - 1);
	}
	else if (type == "a") {
		client.debts.push_back(changes);
	}
}
void ClientProfileEditor::change_reservation(string type, string changes) {
	if (type == "d") {
		client.reservation.erase(client.reservation.begin() + stoi(changes) - 1);
	}
	else if (type == "a") {
		client.reservation.push_back(changes);
	}
}
/*
void ClientProfileEditor::change_reservation() {
	cout << "\n You want delete or add? (d/a): ";
	string answer; getline(cin, answer);
	if (answer == "d") {
		int index;
		cout << " What number to delete?"; cin >> index;
		client.reservation.erase(client.reservation.begin() + index - 1);
		cin.ignore();
	}
	else if (answer == "a") {
		cout << " Enter what you want to add: ";
		string str; getline(cin, str);
		client.reservation.push_back(str);
	}

}
*/