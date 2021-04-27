#include "Client_header.h"
#include <string>
using namespace std;

string Date::get_date() {
	return to_string(day) + "." + to_string(month) + "." + to_string(year);
}

Client::Client(string name, string surname, Date date, string phone, string address, string login, string password)
{
	this->name = name;
	this->surname = surname;
	this->date_of_birth = date;
	this->phone_number = phone;
	this->address = address;
	this->login = login;
	this->password = password;
}

string get_more_info(Client c) {
	string info = " Phonenumber: " + c.phone_number + "\n Address: " + c.address + "\n\n";
	return info;
}

string get_main_info(Client c) {
	string info = "\n Name: " + c.name + "\n Surname: " + c.surname ;
	string date = "\n Date of birth: " + c.date_of_birth.get_date();
	string log = "\n Login: " + c.login + "\ Password: " + c.password;
	return info + date + log;
}
string get_name_sur(Client c) {
	return "\n Name: " + c.name + "\n Surname: " + c.surname;
}


string get_debts_info(Client c) {
	string str = "\n\t";
	for (int i = 0; i < c.debts.size(); i++) {
		str += c.debts[i] + ";\n\t";
	}
	return str;
}
string get_reservation_info(Client c) {
	string str = "\n\t";
	for (int i = 0; i < c.reservation.size(); i++) {
		str += c.reservation[i] + ";\n\t";
	}
	return str;
}
string get_history_info(Client c) {
	string str = "\n\t";
	for (int i = 0; i < c.history.size(); i++) {
		str += c.history[i] + ";\n\t";
	}
	return str;
}


