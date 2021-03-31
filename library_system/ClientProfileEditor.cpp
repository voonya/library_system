#include "ClientProfileEditor.h"



Client ClientProfileEditor::find_client(vector<Client> DB, string name, string surname, string phonenumber, int& index) {
	Client client;
	for (int i = 0; i < DB.size(); i++) {
		if (DB[i].name == name && DB[i].surname == surname && DB[i].phone_number == phonenumber) {
			client = DB[i];
			index = i;
			return client;
		}
	}
	client.name = "0";
	return client;
}
void ClientProfileEditor::update_info(Client client, vector<Client>& DB, int index_in_db) {
	DB[index_in_db] = client;
	cout << get_history_info(DB[index_in_db]);
	cout << " The data has been successfully changed\n";
}

void ClientProfileEditor::change_history() {
	cout << "\n You want delete or add? (d/a): ";
	string answer; getline(cin, answer);
	if (answer == "d") {
		int index;
		cout << " What number to delete? "; cin >> index;
		client.history.erase(client.history.begin() + index - 1);
		cin.ignore();
	}
	else if (answer == "a") {
		cout << " Enter what you want to add: ";
		string str; getline(cin, str);
		client.history.push_back(str);
	}
}
void ClientProfileEditor::show_history() {
	for (int i = 0; i < client.history.size(); i++) {
		cout << "\t" << i + 1 << ") " << client.history[i] << "\n";
	}
}
void ClientProfileEditor::change_debts() {
	cout << "\n You want delete or add? (d/a): ";
	string answer; getline(cin, answer);
	if (answer == "d") {
		int index;
		cout << " What number to delete? "; cin >> index;
		client.debts.erase(client.debts.begin() + index - 1);
		cin.ignore();
	}
	else if (answer == "a") {
		cout << " Enter what you want to add: ";
		string str; getline(cin, str);
		client.debts.push_back(str);
	}

}
void ClientProfileEditor::show_debts() {
	for (int i = 0; i < client.debts.size(); i++) {
		cout << "\t" << i + 1 << ") " << client.debts[i] << "\n";
	}
}
void ClientProfileEditor::show_reservation() {
	for (int i = 0; i < client.reservation.size(); i++) {
		cout << "\t" << i + 1 << ") " << client.reservation[i] << "\n";
	}
}
void ClientProfileEditor::change_reservation() {
	cout << "\n You want delete or add? (d/a)";
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