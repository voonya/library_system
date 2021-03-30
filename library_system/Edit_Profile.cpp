#include "Edit_Profile.h"


Client Edit_Profile::find_client(vector<Client> DB, string name, string surname, string phonenumber, int& index) {
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
void Edit_Profile::update_info(Client client, vector<Client>& DB, int index_in_db) {
	DB[index_in_db] = client;
	cout << " The data has been successfully changed\n";
}

void Edit_Profile::change_history() {
	cout << " You want delete or add? (d/a)";
	string answer; getline(cin, answer);
	if (answer == "d") {
		int index;
		cout << " What number to delete?"; cin >> index;
		client.history.erase(client.history.begin() + index - 1);
		cin.ignore();
	}
	else if (answer == "a") {
		cout << " Enter what you want to add: ";
		string str; getline(cin, str);
		client.history.push_back(str);
	}
}
void Edit_Profile::show_history() {
	for (int i = 0; i < client.history.size(); i++) {
		cout << " " << i + 1 << ") " << client.history[i] << "\n";
	}
}
void Edit_Profile::change_debts() {
	cout << " You want delete or add? (d/a)";
	string answer; getline(cin, answer);
	if (answer == "d") {
		int index;
		cout << " What number to delete?"; cin >> index;
		client.debts.erase(client.debts.begin() + index - 1);
		cin.ignore();
	}
	else if (answer == "a") {
		cout << " Enter what you want to add: ";
		string str; getline(cin, str);
		client.debts.push_back(str);
	}

}
void Edit_Profile::show_debts() {
	for (int i = 0; i < client.debts.size(); i++) {
		cout << " " << i + 1 << ") " << client.debts[i] << "\n";
	}
}
void Edit_Profile::show_reservation() {
	for (int i = 0; i < client.reservation.size(); i++) {
		cout << " " << i + 1 << ") " << client.reservation[i] << "\n";
	}
}
void Edit_Profile::change_reservation() {
	cout << " You want delete or add? (d/a)";
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