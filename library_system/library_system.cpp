
#include "Librarian.h"
#include "User.h"

int main()
{
	
	vector<Client> clientVector;
	ClientDatabase DB_Clients(clientVector);
	DB_Clients.fake_init();

	
	vector<Book> bookVector;
	BookDatabase book_database(bookVector);
	book_database.fake_init();


	Librarian lib("Name","Name", "Phone"); 
	User user(&(*DB_Clients.getAllClients())[1]);
	//lib.start_menu(&DB_Clients, &book_database);
	user.start_menu(&book_database,&DB_Clients);
	return 0;
}
