#include "Interface_NewClient.h"
#include "Menu_Edit_Profile.h"
#include <iostream>
vector<Client> DB_Clients;


int main()
{
	Interface_NewClient menu;
	menu.start_menu(DB_Clients);
	return 0;
}

