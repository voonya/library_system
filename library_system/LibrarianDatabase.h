#pragma once
#include "Librarian.h"
#include <vector>



using namespace std;
class LibrarianDatabase
{
	vector< Librarian > librarians;
public:
	LibrarianDatabase(std::vector<Librarian> librarians);
	void fake_init();
	void addLibrarianToDatabase(const Librarian& librarian);
	void removeLibrarianFromDatabase(Librarian* librarian);
	void editLibrarian(Librarian* librarian, string newName, string newSurname, string newPhone);
	vector< Librarian* > findByNameAndSurname(string name, string surname);
	vector< Librarian >* getAllLibrarians();
	vector< Librarian > sort_by_surname();
	vector< Librarian > sort_by_name();
};

