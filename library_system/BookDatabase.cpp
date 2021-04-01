#include <vector>
#include <string>
#include "BookDatabase.h"

using namespace std;

int BookDatabase::bookId = 0;

bool authorComparator(Book book1, Book book2) {
	return book1.getAuthor() > book2.getAuthor();
}

bool titleComparator(Book book1, Book book2) {
	return book1.getTitle() > book2.getTitle();
}

bool yearComparator(Book book1, Book book2) {
	return book1.getYear() > book2.getYear();
}

void BookDatabase::addBookToDatabase(string title, string author, int year, int pages, string additionalInfo){
	BookDatabase::bookId++;
	queue< Booking > bookingQueue;
	Book newBook(BookDatabase::bookId, title, author, year, pages, additionalInfo, bookingQueue);
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

void BookDatabase::editBook(Book* book, string newTitle, string newAuthor, int newYear, int newPages, string newAdditionalInfo){
	book->setTitle(newTitle);
	book->setAuthor(newAuthor);
	book->setYear(newYear);
	book->setPages(newPages);
	book->setAdditionalInfo(newAdditionalInfo);
}

void BookDatabase::bookTheBook(Book* book, Client* client){
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

vector<Book> BookDatabase::sortBooksByAuthor()
{
	sort(books.begin(), books.end(), authorComparator);
	return books;
}

vector<Book> BookDatabase::sortBooksByTitle()
{
	sort(books.begin(), books.end(), titleComparator);
	return books;
}

vector<Book> BookDatabase::sortBooksByYear()
{
	sort(books.begin(), books.end(), yearComparator);
	return books;
}