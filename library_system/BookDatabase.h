#pragma once
#include <string>
#include <vector>
#include <queue>
#include "Client_header.h"
#include "Book.h"

using namespace std;

bool authorComparator(Book book1, Book book2);
bool titleComparator(Book book1, Book book2);
bool yearComparator(Book book1, Book book2);

class BookDatabase {
	vector< Book > books;
	static int bookId;
public:
	BookDatabase(vector<Book> books);
	void fake_init();
	vector<Book>* BookDatabase::getAllBooksPointer();
	void addBookToDatabase(string title, string author, int year, int pages, string additionalInfo);
	void removeBookFromDatabase(Book* book);
	void editBook(Book* book, string newTitle, string newAuthor, int newYear, int newPages, string newAdditionalInfo);
	void bookTheBook(Book* book, Client* client);
	void removeTopBooking(Book* book);
	void takeTheBook(Book* book, Client* client);
	vector< Book > findByAuthor(string author);
	vector< Book > findBooks(string title, string author);
	int getBookNumber(Book book);
	vector< Book > findByTitle(string title);
	vector< Book >& getAllBooks();
	vector< Book > sortBooksByAuthor();
	vector< Book > sortBooksByTitle();
	vector< Book > sortBooksByYear();
};