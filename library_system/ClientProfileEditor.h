#pragma once
#include "Client_header.h"
#include <iostream>
class ClientProfileEditor
{
protected:
	Client client;
	int index_in_db;
	Client find_client(vector<Client> DB, string name, string surname, string phonenumber);
	void update_info(Client client, vector<Client>& DB);
	void change_name(string name) { client.name = name; }
	void change_surname(string surname) { client.surname = surname; }
	void change_phone_number(string phone_number) { client.phone_number = phone_number; }
	void change_address(string address) { client.address = address;}
	void change_date(int d, int m, int y) {
		client.date_of_birth = Date(d,m,y); 
	}
	void change_history(string type, string changes);
	void change_debts(string type, string changes);
	void change_reservation(string type, string changes);
	vector <int> convert_to_date(char line[]);
};

