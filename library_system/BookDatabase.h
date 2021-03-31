#pragma once
#include <string>
#include <vector>
#include <queue>
#include "Client_header.h"
#include "Book.h"

using namespace std;

class BookDatabase {
	vector< Book > books;
	static int bookId;
public:
	void addBookToDatabase(string title, string author, int pages, string additionalInfo);
	void removeBookFromDatabase(Book* book);
	void editBook(Book* book, string newTitle, string newAuthor, int newPages, string newAdditionalInfo);
	void BookTheBook(Book* book, Client* client);
	vector< Book > findByAuthor(string author);
	vector< Book > findByTitle(string title);
	vector< Book > getAllBooks();
};