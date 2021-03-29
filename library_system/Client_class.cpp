#include "Client_header.h"
#include <string>
using namespace std;

string Date::get_date() {
	return to_string(day) + "." + to_string(month) + "." + to_string(year);
}
