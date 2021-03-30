#pragma once
#include "NewClient.h"
class Interface_NewClient
{
	NewClient client;
	//vector<Client> DB;
public:
	/*
	Interface_NewClient(vector<Client> db) {
		DB = db;
	}*/
	void work_loop(string& answer, vector<Client>& DB);
	void start_menu(vector<Client>& DB);
	void set_info();
};

