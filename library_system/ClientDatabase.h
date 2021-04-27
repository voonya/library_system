#pragma once
#include <vector>

#include "Client_header.h"

class ClientDatabase
{
	std::vector< Client > clients;
public:
	ClientDatabase(std::vector<Client> clients);
	void fake_init();
	void addClientToDatabase(const Client& client);
	void removeClientFromDatabase(Client* client);
	void editClient(Client* client, string newName, string newSurname, Date newBirth, string newPhone);
	vector< Client* > findByNameAndSurname(string name, string surname);
	int findByNameAndSurnameAndPhone(string name, string surname, string phonenumber);
	bool checkLogin(string login);
	bool checkPass(string pass);
	vector< Client >* getAllClients();
	vector< Client > sort_by_surname();
	vector< Client > sort_by_name();
	Client* getClientByIndex(int index);
};

