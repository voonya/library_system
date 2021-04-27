#include <vector>
#include <string>
#include "ClientDatabase.h"

#include <algorithm>

using namespace std;

ClientDatabase::ClientDatabase(std::vector<Client> clients)
{
	this->clients = clients;
}

void ClientDatabase::fake_init()
{
	Client client1("Vasya", "Pupkin", Date(3, 12, 2000), "+3809944343", "-","1234","qwerty");
	Client client2("Lena", "Pupkina", Date(3, 12, 2000), "+3809942343", "-", "228", "322");
	Client client3("Olya", "Hink", Date(8, 11, 2002), "+38099412343", "-", "olya", "aezakmi");
	Client client4("v", "v", Date(8, 11, 2002), "v", "-", "v", "v");
	addClientToDatabase(client1);
	addClientToDatabase(client2);
	addClientToDatabase(client3);
	addClientToDatabase(client4);
}

Client* ClientDatabase::getClientByIndex(int index)
{
	return &clients[index];
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


vector<Client*> ClientDatabase::findByNameAndSurname(string name, string surname) {
	vector< Client* > response;
	for (int i = 0; i < clients.size(); i++) {
		if (clients[i].name.find(name) != -1 && clients[i].surname.find(name))
			response.push_back(&clients[i]);
	}
	return response;
}
int ClientDatabase::findByNameAndSurnameAndPhone(string name, string surname, string phonenumber) {
	for (int i = 0; i < clients.size(); i++) {
		if (clients[i].name == name && clients[i].surname == surname && clients[i].phone_number == phonenumber)
			return i;
	}
	return -1;
}

bool sorting_func_name(Client a, Client b)
{
	return a.name < b.name;
}

bool sorting_func_surname(Client a, Client b)
{
	return a.surname < b.surname;
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

bool ClientDatabase::checkLogin(string login) {
	for (int i = 0; i < clients.size(); i++) {
		if (clients[i].login.compare(login) == 0) return false;
	}
	return true;
}
bool ClientDatabase::checkPass(string password) {
	for (int i = 0; i < clients.size(); i++) {
		if (clients[i].password.compare(password) == 0) return false;
	}
	return true;
}


