#include <vector>
#include <string>
#include "ClientDatabase.h"

#include <algorithm>

using namespace std;

ClientDatabase::ClientDatabase(std::vector<Client> clients)
{
	this->clients = clients;
}

void ClientDatabase::addClientToDatabase(const Client& client) {
	clients.push_back(client);
}

void ClientDatabase::removeClientFromDatabase(Client* client) {
	int numberRemovingClient = -1;
	for (int i = 0; i < clients.size(); i++)
		if ((&clients[i]) == client) {
			numberRemovingClient = i;
			break;
		}
	if (numberRemovingClient != -1) {
		clients.erase(clients.begin() + numberRemovingClient);
	}
}

void ClientDatabase::editClient(Client* client, string newName, string newSurname, Date newBirth, string newPhone)
{
	client->name = newName;
	client->surname = newSurname;
	client->date_of_birth = newBirth;
	client->phone_number = newPhone;
}


vector<Client> ClientDatabase::findByNameAndSurname(string name, string surname) {
	vector< Client > response;
	for (int i = 0; i < clients.size(); i++) {
		if (clients[i].name.find(name) != -1 && clients[i].surname.find(name))
			response.push_back(clients[i]);
	}
	return response;
}

bool sorting_func_name(Client a, Client b)
{
	return a.name > b.name;
}

bool sorting_func_surname(Client a, Client b)
{
	return a.surname > b.surname;
}

vector<Client>* ClientDatabase::getAllClients()
{
	return &clients;
}

vector< Client > ClientDatabase::sort_by_name()
{
	vector<Client> new_catalogue = *getAllClients();
	sort(new_catalogue.begin(), new_catalogue.end(), sorting_func_name);
	return new_catalogue;
}

vector< Client > ClientDatabase::sort_by_surname()
{
	vector<Client> new_catalogue = *getAllClients();
	sort(new_catalogue.begin(), new_catalogue.end(), sorting_func_surname);
	return new_catalogue;
}



