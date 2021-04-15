
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

	int tryAgain = true;
	while (tryAgain)
	{
		tryAgain = false;
	cout << "Do you want to register or log in (1/2):" << endl;
	int answer;
	cin >> answer;
	switch (answer)
	{
	case 1:
	{
		ClientRegestrationInterface reg;
		reg.start_menu(&DB_Clients);
		tryAgain = true;
		break;
	}
	default:
	{
		LoginForm login;
		int typeOfUser = login.askUserType();
		// client
		bool found = false;
		while (!found)
		{
			cout << "To log in - 1, to return and choose between registration and log in - 2" << endl;
			int answer1;
			cin >> answer1;
			if (answer1 == 2)
			{
				tryAgain = true;
				break;
			}
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
				int librarianIndex = login.getLibrarianIndex(librarianDatabase, found);
				if (!found)
				{
					continue;
				}
				Librarian* librarian = librarianDatabase.getLibrarianByIndex(librarianIndex);
				librarian->start_menu(&DB_Clients, &book_database);
			}
		}
	}
	}
	}
	
	
	
	//lib.start_menu(&DB_Clients, &book_database);
	return 0;
}
