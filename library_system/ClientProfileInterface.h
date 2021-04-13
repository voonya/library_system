#pragma once
#include "ClientProfileEditor.h"

class ClientProfileInterface : protected ClientProfileEditor
{
	void show_history();
	void show_reservation();
	void show_debts();
public:
	void start_menu(vector<Client>* DB);
	void change_menu(vector<Client>* DB);
	void show_info();
	
};

