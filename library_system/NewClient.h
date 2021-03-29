#include "Client_header.h"

class NewClient
{
	Client client;
public:
	void set_date_birth(int d, int m, int y) {
		client.date_of_birth.day = d;
		client.date_of_birth.month = m;
		client.date_of_birth.year = y;
	}
	void set_name(string n) { client.name = n; }
	void set_surname(string s) { client.surname = s; }
	void set_phone_number(string n) { client.phone_number = n; }
	void set_address(string a) { client.address = a; }
	vector<string> get_debts_list() { return client.debts; }
	vector<string> get_reservation_list() { return client.reservation; }
	//void add_book_reservation(string book) { client.reservation.push_back(book); }
	//void add_book_debts(string book) { client.debts.push_back(book); }*/
	string add_new_client(vector<Client> DB);
};

string get_main_info(Client c);
string get_more_info(Client c);