#include "ClientRegestrationInterface.h"
#include "ClientProfileInterface.h"
#include <iostream>
vector<Client> DB_Clients;


int main()
{
	ClientRegestrationInterface menu;
	menu.start_menu(DB_Clients);
	ClientProfileInterface menu2;
	menu2.start_menu(DB_Clients);
	return 0;
}

