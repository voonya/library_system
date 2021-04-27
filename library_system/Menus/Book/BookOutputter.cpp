#pragma once
#include "BookOutputter.h"

#include <iostream>

void book_outputter::output_book(Book book)
{
	cout << book.title << " by " << book.author << endl;
}
