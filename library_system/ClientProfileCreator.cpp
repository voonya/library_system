#include "ClientProfileCreator.h"

vector<int> ClientProfileCreator::convert_to_date(char line[]) {
	vector<int> date;
	char sep[] = ".";
	char* pos = strtok(line, sep);
	while (pos != NULL) {
		char word_c[100];
		date.push_back(stoi(pos));
		pos = strtok(NULL, sep);
	}
	return date;
}