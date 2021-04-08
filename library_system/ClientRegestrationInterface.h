#pragma once
#include "ClientProfileCreator.h"
class ClientRegestrationInterface
{
	ClientProfileCreator client;
public:
	void work_loop(string& answer, ClientDatabase* DB);
	void start_menu(ClientDatabase* DB);
	void set_info();
};