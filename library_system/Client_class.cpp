#include "Client_header.h"
#include <string>
using namespace std;

string Date::get_date() {
	return to_string(day) + "." + to_string(month) + "." + to_string(year);
}

string get_more_info(Client c) {
	string info = " Phonenumber: " + c.phone_number + "\n Address: " + c.address + "\n\n";
	return info;
}

string get_main_info(Client c) {
	string info = " Name: " + c.name + "\n Surname: " + c.surname ;
	string date = "\n Date of birth: " + c.date_of_birth.get_date();
	return info + date;
}

string get_debts_info(Client c) {
	string str;
	for (int i = 0; i < c.debts.size(); i++) {
		str += c.debts[i] + ",\n";
	}
	return str;
}
string get_reservation_info(Client c) {
	string str;
	for (int i = 0; i < c.debts.size(); i++) {
		str += c.reservation[i] + ",\n";
	}
	return str;
}
string get_history_info(Client c) {
	string str;
	for (int i = 0; i < c.debts.size(); i++) {
		str += c.history[i] + ",\n";
	}
	return str;
}