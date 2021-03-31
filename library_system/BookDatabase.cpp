#include <vector>
#include <string>
#include "BookDatabase.h"

using namespace std;

int BookDatabase::bookId = 0;

void BookDatabase::addBookToDatabase(string title, string author, int pages, string additionalInfo){
	BookDatabase::bookId++;
	queue< Booking > bookingQueue;
	Book newBook(BookDatabase::bookId, title, author, pages, additionalInfo, bookingQueue);
	books.push_back(newBook);
}


void BookDatabase::removeBookFromDatabase(Book* book){
	int numberRemovingBook = -1;
	for (int i = 0; i < books.size(); i++)
		if ((&books[i]) == book) {
			numberRemovingBook = i;
			break;
		}
	if (numberRemovingBook != -1) {
		books.erase(books.begin() + numberRemovingBook);
	}
}

void editBook(Book* book, string newTitle, string newAuthor, int newPages, string newAdditionalInfo){
	book->setTitle(newTitle);
	book->setAuthor(newAuthor);
	book->setPages(newPages);
	book->setAdditionalInfo(newAdditionalInfo);
}

void BookTheBook(Book* book, Client* client){
	Booking newBooking;
	newBooking.client = client;
	book->addBookingElement(newBooking);
}

vector<Book> BookDatabase::findByAuthor(string author){
	vector< Book > response;
	for (int i = 0; i < books.size(); i++) {
		if (books[i].getAuthor().find(author) != -1)
			response.push_back(books[i]);
	}
	return response;
}

vector<Book> BookDatabase::findByTitle(string title){
	vector< Book > response;
	for (int i = 0; i < books.size(); i++) {
		if (books[i].getTitle().find(title) != -1)
			response.push_back(books[i]);
	}
	return response;
}

vector<Book> BookDatabase::getAllBooks()
{
	return books;
}

