#pragma once
#include "ClientProfileEditor.h"

class ClientProfileInterface : protected ClientProfileEditor
{
public:
	//Menu_Edit_Profile() {};
	void start_menu(vector<Client>& DB);
	void change_menu(vector<Client>& DB);
	void show_info();
};

