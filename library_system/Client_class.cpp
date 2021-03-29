#include "Client_header.h"
#include <string>
using namespace std;


string Client::get_more_info() {
	string info = " Phonenumber: " + phone_number + "\n Address: " + address + "\n";
	return info;
}

string Client::get_main_info() {
	string info = " Surname: " + surname + "\n Name: " + name;
	string date = "\n Date of birth: " + to_string(date_of_birth.day) + "." + to_string(date_of_birth.month) + "." + to_string(date_of_birth.year);
	return info + date;
}