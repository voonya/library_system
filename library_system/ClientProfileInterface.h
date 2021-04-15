#pragma once
#include "ClientProfileEditor.h"

class ClientProfileInterface : protected ClientProfileEditor
{
	void show_history();
	void show_reservation();
	void show_debts();
	void show_info();
	void change_menu(vector<Client>* DB);
public:
	void start_menu(vector<Client>* DB);
	void show_info(Client client);
};

