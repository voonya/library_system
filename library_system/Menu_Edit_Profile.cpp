#include "Menu_Edit_Profile.h"


void Menu_Edit_Profile::start_menu(vector<Client>& DB) {
	cout << " It`s menu of changing profile of clients\n";
	cout << " If you want to start enter 'start'\n If you want to quit enter 'q'";
	string answer;
	getline(cin, answer);
	while (answer != "q") {
		if (answer == "start") {
			string name, surname, phonenumber;
			cout << " Enter name: ";
			getline(cin, name);
			cout << " Enter surname: ";
			getline(cin, surname);
			cout << " Enter phonenumber: ";
			getline(cin, phonenumber);
			client = find_client(DB, name, surname, phonenumber, index_in_db);
			show_info();
			change_menu(DB);
			show_info();
		}
		// подряд несколько изменить
	}

}

void Menu_Edit_Profile::change_menu(vector<Client>& DB) {
	cout << " What you want to change: name, surname, phonenumber, date of bith, address, debts, reservation or history?\n Enter (1/2/3/4/5/6/7/8): ";
	string answer; getline(cin, answer);
	if (answer == "1") {
		cout << " Input new name: "; 
		string n; getline(cin, n);
		change_name(n);
	}
	else if (answer == "2") {
		cout << " Input new surname: ";
		string n; getline(cin, n);
		change_surname(n);
	}
	else if (answer == "3") {
		cout << " Input new phonenumber: ";
		string n; getline(cin, n);
		change_phone_number(n);
	}
	else if (answer == "4") {
		cout << " Input new date of birth: ";
		string n; getline(cin, n);
		change_phone_number(n);
	}
	else if (answer == "5") {
		cout << " Input new address: ";
		string n; getline(cin, n);
		change_address(n);
	}
	else if (answer == "6") {
		show_debts();
		change_debts();
	}
	else if (answer == "7") {
		show_reservation();
		change_reservation();
	}
	else if (answer == "8") {
		show_history();
		change_history();
	}
	update_info(client, DB, index_in_db);
}

void Menu_Edit_Profile::show_info() {
	cout << get_main_info(client) << "\n" << get_more_info(client);
	cout << " Debts:\n" << get_debts_info(client);
	cout << " Reservation:\n" << get_reservation_info(client);
	cout << " History:\n" << get_history_info(client);
}