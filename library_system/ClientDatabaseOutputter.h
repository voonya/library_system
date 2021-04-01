#pragma once
#include "ClientDatabase.h"
class ClientDatabaseOutputter
{
private:
	ClientDatabase* database;
public:
	ClientDatabaseOutputter(ClientDatabase* database);
	void output_client_database();
	string request_client_info(Client client);
};

