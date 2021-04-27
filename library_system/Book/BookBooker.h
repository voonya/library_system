#pragma once
#include "Book.h"
#include "../Databases/BookDatabase.h"
#include "../Client/Client_header.h"

class BookBooker {
public:
	friend class BookDatabase;
	void bookTheBook(BookDatabase& DB, Book* book, Client* client);
	void takeTheBook(BookDatabase& DB, Book* book, Client* client);
};