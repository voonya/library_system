#pragma once
#include <string>
#include <vector>
using namespace std;


class Date {
	int day;
	int month;
	int year;
public:
	Date() {};
	Date(int d, int m, int y) : day(d), month(m), year(y) {};
	string get_date();
	friend class Client;
	friend class ClientProfileCreator;
};

class Client {
	string name;
	string surname;
	Date date_of_birth;
	string phone_number;
	string address;
	vector<string> debts;
	vector<string> reservation;
	vector<string> history;
public:
	Client(string name, string surname, Date date, string phone, string address);
	Client() { date_of_birth = Date(1, 1, 2000); }
	friend class ClientProfileCreator;
	friend class ClientProfileEditor;
	friend string get_main_info(Client c);
	friend string get_more_info(Client c);
	friend string get_debts_info(Client c);
	friend string get_reservation_info(Client c);
	friend string get_history_info(Client c);
	friend class ClientDatabase;
	friend bool sorting_func_name(Client a, Client b);
	friend bool sorting_func_surname(Client a, Client b);
};
/*
	void set_date_birth(int d, int m, int y) {
		date_of_birth.day = d;
		date_of_birth.month = m;
		date_of_birth.year = y;
	}
	void set_name(string n) { name = n; }
	void set_surname(string s) { surname = s; }
	void set_phone_number(string n) { phone_number = n; }
	void set_address(string a) { address = a; }
	vector<string> get_debts_list() { return debts; }
	vector<string> get_reservation_list() { return reservation; }
	void add_book_reservation(string book) { reservation.push_back(book); }
	void add_book_debts(string book) { debts.push_back(book); }
	string get_main_info();
	string get_more_info();*/