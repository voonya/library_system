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
	friend class Human;
	friend class Client;
	friend class ClientProfileCreator;
};

class Client {
	string name;
	string surname;
	Date date_of_birth;
	string phone_number;
	string address;
	string login;
	string password;
	vector<string> debts;
	vector<string> reservation;
	vector<string> history;
public:
	Client(string name, string surname, Date date, string phone, string address,string login, string password);
	Client() { date_of_birth = Date(1, 1, 2000); }
	friend vector<string> get_info_table(Client c);
	friend class ClientProfileCreator;
	friend class ClientProfileEditor;
	friend string get_main_info(Client c);
	friend string get_more_info(Client c);
	friend string get_debts_info(Client c);
	friend string get_reservation_info(Client c);
	friend string get_history_info(Client c);
	friend string get_name_sur(Client C);
	friend class ClientDatabase;
	friend bool sorting_func_name(Client a, Client b);
	friend bool sorting_func_surname(Client a, Client b);
	//friend Client* findClient(vector<Client>& DB, string name, string surname);
	friend class BookDatabase;
	friend class ClientProfileInterface;
	friend class LoginForm;
};
