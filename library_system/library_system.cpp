
#include "Librarian.h"
#include "LibrarianDatabase.h"
#include "LoginForm.h"
#include "User.h"

int main()
{
	
	vector<Client> clientVector;
	ClientDatabase DB_Clients(clientVector);
	DB_Clients.fake_init();

	
	vector<Book> bookVector;
	BookDatabase book_database(bookVector);
	book_database.fake_init();

	vector<Librarian> librarianVector;
	LibrarianDatabase librarianDatabase(librarianVector);
	librarianDatabase.fake_init();
	LoginForm login;
	int typeOfUser = login.askUserType();
	// client
	bool found = false;
	while (!found)
	{
		if (typeOfUser == 1)
		{
			int userIndex = login.getUserIndex(DB_Clients, found);
			if (!found)
			{
				continue;
			}
			Client* client = DB_Clients.getClientByIndex(userIndex);
			User user(client);
			user.start_menu(&book_database, &DB_Clients);
		}
		// librarian
		else
		{

		}
	}
	
	//lib.start_menu(&DB_Clients, &book_database);
	return 0;
}
