#pragma once
#include "ClientDatabase.h"
#include "Librarian.h"
#include "LibrarianDatabase.h"

class LoginForm
{
public:
	int askUserType();
	int getUserIndex(ClientDatabase& DB, bool& found);
	int getLibrarianIndex(LibrarianDatabase librarian_database, bool& found);
};

