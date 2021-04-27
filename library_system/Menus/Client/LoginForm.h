#pragma once
#include "../../Databases/ClientDatabase.h"
#include "../../Actors/Librarian.h"
#include "../../Databases/LibrarianDatabase.h"

class LoginForm
{
public:
	int askUserType();
	int getUserIndex(ClientDatabase& DB, bool& found);
	int getLibrarianIndex(LibrarianDatabase librarian_database, bool& found);
};

