#include "BookBooker.h"

void BookBooker::bookTheBook(BookDatabase& DB, Book* book, Client* client)
{
	DB.bookTheBook(book, client);
}

void BookBooker::takeTheBook(BookDatabase& DB, Book* book, Client* client)
{
	DB.takeTheBook(book, client);
}