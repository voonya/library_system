#pragma once
#include "Client_header.h"
#include <iostream>
class Edit_Profile
{
public:
	Client client;
	int index_in_db;
	Edit_Profile(vector<Client> DB, string name, string surname, string phonenumber) {
		index_in_db = -1;
		client = find_client(DB,name,surname,phonenumber, index_in_db);
	}
	Client find_client(vector<Client> DB, string name, string surname, string phonenumber, int &index_in_db);
	void update_info(Client client, vector<Client>& DB, int index_in_db);
	void change_name(string name) { client.name = name; }
	void change_surname(string surname) { client.surname = surname; }
	void change_phone_number(string phone_number) { client.phone_number = phone_number; }
	void change_address(string address) { client.address = address;}
	void change_date(int d, int m, int y) {
		client.date_of_birth = Date(d,m,y); 
	}
	void show_history();
	void change_history();
	void show_debts();
	void change_debts();
	void show_reservation();
	void change_reservation();
};
