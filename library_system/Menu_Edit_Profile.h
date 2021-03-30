#pragma once
#include "Edit_Profile.h"

class Menu_Edit_Profile: public Edit_Profile
{

public:
	void start_menu(vector<Client>& DB);
	void change_menu(vector<Client>& DB);
	void show_info();
};

