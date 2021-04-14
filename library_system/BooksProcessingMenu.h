#pragma once
#include "BookDatabase.h"

class BooksProcessingMenu {
public:
	void startDialogMenu(BookDatabase& DB);
	void showBooks(BookDatabase& DB);
	void showBooks(vector<Book> DB);
	void addNewBook(BookDatabase& DB, string title, string author, int year, int pages, string additionalInfo);
	void editBook(BookDatabase& DB, int bookNumber, string newTitle, string newAuthor, int newYear, int newPages, string newAdditionalInfo);
	void removeBook(BookDatabase& DB, int bookNumber);
	int request_book(int& number, BookDatabase& DB);
};