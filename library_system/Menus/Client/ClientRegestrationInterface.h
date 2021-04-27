#pragma once
#include "../../Client/ClientProfileCreator.h"
#include "../../Databases/ClientDatabase.h"
class ClientRegestrationInterface
{
	ClientProfileCreator client;
public:
	void work_loop(string& answer, ClientDatabase* DB);
	void start_menu(ClientDatabase* DB);
	void set_info(ClientDatabase* DB);
};