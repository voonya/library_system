#pragma once
#include "Book.h"
#include "BookDatabase.h"
#include "Client_header.h"

class BookBooker {
public:
	friend class BookDatabase;
	void bookTheBook(BookDatabase& DB, Book* book, Client* client);
	void takeTheBook(BookDatabase& DB, Book* book, Client* client);
};