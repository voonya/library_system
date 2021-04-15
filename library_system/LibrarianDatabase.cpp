#include "LibrarianDatabase.h"
#include "ClientDatabase.h"
#include <vector>
#include <string>

#include <algorithm>



using namespace std;

LibrarianDatabase::LibrarianDatabase(std::vector<Librarian> librarians)
{
	this->librarians = librarians;
}

void LibrarianDatabase::fake_init()
{
	Librarian librarian1("Vitya", "Petrenko", "+3809944343");
	Librarian librarian2("Lia", "Mars", "+3809942343");
	Librarian librarian3("Irina", "Mukha", "+38099412343");
	addLibrarianToDatabase(librarian1);
	addLibrarianToDatabase(librarian2);
	addLibrarianToDatabase(librarian3);
}

void LibrarianDatabase::addLibrarianToDatabase(const Librarian& librarian) {
	librarians.push_back(librarian);
}

void LibrarianDatabase::removeLibrarianFromDatabase(Librarian* librarian) {
	int numberRemovingLibrarian = -1;
	for (int i = 0; i < librarians.size(); i++)
		if ((&librarians[i]) == librarian) {
			numberRemovingLibrarian = i;
			break;
		}
	if (numberRemovingLibrarian != -1) {
		librarians.erase(librarians.begin() + numberRemovingLibrarian);
	}
}

void LibrarianDatabase::editLibrarian(Librarian* librarian, string newName, string newSurname, string newPhone)
{
	librarian->name = newName;
	librarian->surname = newSurname;
	librarian->phone_number = newPhone;
}


vector<Librarian*> LibrarianDatabase::findByNameAndSurname(string name, string surname) {
	vector< Librarian* > response;
	for (int i = 0; i < librarians.size(); i++) {
		if (librarians[i].name.find(name) != -1 && librarians[i].surname.find(name))
			response.push_back(&librarians[i]);
	}
	return response;
}

bool sorting_func_name_l(Librarian a, Librarian b)
{
	return a.name < b.name;
}

bool sorting_func_surname_l(Librarian a, Librarian b)
{
	return a.surname < b.surname;
}

vector<Librarian>* LibrarianDatabase::getAllLibrarians()
{
	return &librarians;
}

Librarian* LibrarianDatabase::getLibrarianByIndex(int index)
{
	return &librarians[index];
}

vector< Librarian > LibrarianDatabase::sort_by_name()
{
	vector<Librarian> new_catalogue = *getAllLibrarians();
	sort(new_catalogue.begin(), new_catalogue.end(), sorting_func_name_l);
	return new_catalogue;
}

vector< Librarian > LibrarianDatabase::sort_by_surname()
{
	vector<Librarian> new_catalogue = *getAllLibrarians();
	sort(new_catalogue.begin(), new_catalogue.end(), sorting_func_surname_l);
	return new_catalogue;
}




