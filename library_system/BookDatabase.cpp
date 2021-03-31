#include <vector>
#include <string>
#include "BookDatabase.h"

using namespace std;

int BookDatabase::bookId = 0;

void BookDatabase::addBookToDatabase(string title, string author, int pages, string additionalInfo){
	Book newBook;
	BookDatabase::bookId++;
	queue< Booking > bookingQueue;
	newBook.id = bookId;
	newBook.title = title;
	newBook.author = author;
	newBook.pages = pages;
	newBook.additionalInfo = additionalInfo;
	newBook.bookingQueue = bookingQueue;
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

void BookDatabase::editBook(Book* book, string newTitle, string newAuthor, int newPages, string newAdditionalInfo){
	book->title = newTitle;
	book->author = newAuthor;
	book->pages = newPages;
	book->additionalInfo = newAdditionalInfo;
}

void BookDatabase::BookTheBook(Book* book, Client* client){
	Booking newBooking;
	newBooking.book = book;
	newBooking.client = client;
	book->bookingQueue.push(newBooking);
}

vector<Book> BookDatabase::findByAuthor(string author){
	vector< Book > response;
	for (int i = 0; i < books.size(); i++) {
		if (books[i].author.find(author) != -1)
			response.push_back(books[i]);
	}
	return response;
}

vector<Book> BookDatabase::findByTitle(string title){
	vector< Book > response;
	for (int i = 0; i < books.size(); i++) {
		if (books[i].title.find(title) != -1)
			response.push_back(books[i]);
	}
	return response;
}

vector<Book> BookDatabase::getAllBooks()
{
	return books;
}

