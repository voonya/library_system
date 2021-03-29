#include <string>
#include <vector>
using namespace std;


class Date {
	int day;
	int month;
	int year;
public:
	Date(int d, int m, int y) : day(d), month(m), year(y) {};
	/*
	void set_day(int d) { day = d;}
	void set_month(int m) { month = m; }
	void set_year(int y) { year = y; }
	int get_day() { return day; }
	int get_month() { return month; }
	int get_year() { return year; }
	*/
	friend class Client;
};

class Client {
	string name;
	string surname;
	Date date_of_birth;
	string phone_number;
	string address;
	vector<string> debts;
	vector<string> reservation;
public:
	Client(string n, string s) : name(n), surname(s), date_of_birth(Date(1,1,2000)) {};
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
	string get_more_info();
};
