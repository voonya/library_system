#pragma once
#include "ClientProfileCreator.h"
class Interface_NewClient
{
	NewClient client;
	//vector<Client> DB;
public:
	void work_loop(string& answer, vector<Client>& DB);
	void start_menu(vector<Client>& DB);
	void set_info();
};