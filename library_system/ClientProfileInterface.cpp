#include "ClientProfileInterface.h"


void ClientProfileInterface::start_menu(vector<Client>* DB) {
	cout << "\n---------------------------------------------------------------------------------\n";
	cout << "\n It`s menu of changing profile of clients\n";
	cout << " If you want to start enter 's'\n If you want to quit enter 'q'\n ";
	string answer;
	cin.ignore(1);
	getline(cin, answer);
	cout << "\n---------------------------------------------------------------------------------\n";
	while (answer != "q") {
		system("cls");
		if (answer == "s") {
			string name, surname, phonenumber;
			cout << " Enter name: ";
			getline(cin, name);
			cout << " Enter surname: ";
			getline(cin, surname);
			cout << " Enter phonenumber: ";
			getline(cin, phonenumber);
			client = find_client(*DB, name, surname, phonenumber);
			system("cls");
			if (index_in_db != -1) {
				
				change_menu(DB);
				//show_info();
				answer = "q";
			}
			else {
				system("cls");
				cout << "\n---------------------------------------------------------------------------------\n";
				cout << " There is no client with theese data in db\n";
				cout << "\n---------------------------------------------------------------------------------\n";
			}
			
			cout << "\n Do you want to try again or change another client`s profile, enter 'q' if you dont want? (s/q): ";
			getline(cin, answer);
		}
		else {
			cout << " Incorrect command. Try again (s/q): ";
			getline(cin, answer);
		}
	}

}

void ClientProfileInterface::change_menu(vector<Client>* DB) {
	string answer = "";
	while(answer!="q"){
		system("cls");
		cout << "\n---------------------------------------------------------------------------------\n";
		show_info();
		cout << "\n---------------------------------------------------------------------------------\n";
		cout << " What you want to change: (1) name, (2) surname, (3) phonenumber, (4) date of bith,\n (5) address, (6) debts, (7) reservation or (8) history (or quit)?\n Enter (1/2/3/4/5/6/7/8/q): ";
		 getline(cin, answer);
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
			vector<int> date;
			bool flag = false;
			while (!flag) {
				date.clear();
				char line[150];
				cout << " Date of birth (in format 1.1.2000): ";
				cin.getline(line, 150);
				date = convert_to_date(line);
				if (date.size() != 3) {
					flag = false;
					cout << " Incorrect type. Try again.\n";
				}
				else {
					flag = true;
				}
			}
			change_date(date[0],date[1],date[2]);
		}
		else if (answer == "5") {
			cout << " Input new address: ";
			string n; getline(cin, n);
			change_address(n);
		}
		else if (answer == "6") {
			show_debts();
			cout << "\n You want delete or add? (d/a): ";
			string answer; getline(cin, answer);
			if (answer == "d") {
				cout << " What number to delete? ";
				string n;
				getline(cin, n);
				change_debts("d", n);
			}
			else if (answer == "a") {
				cout << " Enter what you want to add: ";
				string str; getline(cin, str);
				change_debts("a", str);
			}
		}
		else if (answer == "7") {
			show_reservation();
			cout << "\n You want delete or add? (d/a): ";
			string answer; getline(cin, answer);
			if (answer == "d") {
				cout << " What number to delete? ";
				string n;
				getline(cin, n);
				change_reservation("d", n);
			}
			else if (answer == "a") {
				cout << " Enter what you want to add: ";
				string str; getline(cin, str);
				change_reservation("a", str);
			}
		}
		else if (answer == "8") {
			show_history();
			cout << "\n You want delete or add? (d/a): ";
			string answer; getline(cin, answer);
			if (answer == "d") {
				cout << " What number to delete? ";
				string n;
				getline(cin, n);
				change_history("d", n);
			}
			else if (answer == "a") {
				cout << " Enter what you want to add: ";
				string str; getline(cin, str);
				change_history("a", str);
			}
		}
		else {
			break;
		}
		update_info(client, *DB);
		cout << " The data has been successfully changed\n";
		//cout << "\n---------------------------------------------------------------------------------\n";
		//show_info();
		//cout << "\n---------------------------------------------------------------------------------\n";
	}
}

void ClientProfileInterface::show_info() {
	cout << get_main_info(client) << "\n" << get_more_info(client);
	cout << " Debts:\n"; show_debts();
	cout << " Reservation:\n"; show_reservation(); //<< get_reservation_info(client);
	cout << " History:\n"; show_history();//<< get_history_info(client);
}
void ClientProfileInterface::show_info(Client client) {
	cout << get_main_info(client) << "\n" << get_more_info(client);
	cout << " Debts:\n"; show_debts();
	cout << " Reservation:\n"; show_reservation(); //<< get_reservation_info(client);
	cout << " History:\n"; show_history();//<< get_history_info(client);
}

void ClientProfileInterface::show_history() {
	for (int i = 0; i < client.history.size(); i++) {
		cout << "\t" << i + 1 << ") " << client.history[i] << "\n";
	}
}

void ClientProfileInterface::show_debts() {
	for (int i = 0; i < client.debts.size(); i++) {
		cout << "\t" << i + 1 << ") " << client.debts[i] << "\n";
	}
}
void ClientProfileInterface::show_reservation() {
	for (int i = 0; i < client.reservation.size(); i++) {
		cout << "\t" << i + 1 << ") " << client.reservation[i] << "\n";
	}
}