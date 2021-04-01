#include "BookBooker.h"

void BookBooker::bookTheBook(BookDatabase& DB, Book* book, Client* client)
{
	DB.bookTheBook(book, client);
}