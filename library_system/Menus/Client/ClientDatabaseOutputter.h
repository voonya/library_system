#pragma once
#include "../../Databases/ClientDatabase.h"
class ClientDatabaseOutputter
{
private:
	ClientDatabase* database;
public:
	ClientDatabaseOutputter(ClientDatabase* database);
	void output_client_database();
	void output_client(Client client);
	string request_client_info(Client client);
};

