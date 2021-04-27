#pragma once
#include "../Client/Client_header.h"
class ClientProfileCreator
{
	Client client;
public:
	void set_date_birth(int d, int m, int y) {
		client.date_of_birth.day = d;
		client.date_of_birth.month = m;
		client.date_of_birth.year = y;
	}
	string get_name() { return client.name; }
	string get_surname() { return client.surname; }
	string get_phone() { return client.phone_number; }
	void set_name(string n) { client.name = n; }
	void set_surname(string s) { client.surname = s; }
	void set_phone_number(string n) { client.phone_number = n; }
	void set_address(string a) { client.address = a; }
	void set_login(string a) { client.login = a;}
	void set_password(string a) { client.password = a; }
	vector<int> convert_to_date(char line[]);
	vector<string> get_debts_list() { return client.debts; }
	vector<string> get_reservation_list() { return client.reservation; }
	Client& get_client() { return client; }
};
