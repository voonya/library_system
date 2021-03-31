#pragma once
#include "ClientProfileCreator.h"
class ClientRegestrationInterface
{
	ClientProfileCreator client;
public:
	void work_loop(string& answer, vector<Client>& DB);
	void start_menu(vector<Client>& DB);
	void set_info();
};