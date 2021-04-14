#include <vector>
#include <string>
#include "BookDatabase.h"

using namespace std;

int BookDatabase::bookId = 0;

bool authorComparator(Book book1, Book book2) {
	return book1.getAuthor() < book2.getAuthor();
}

bool titleComparator(Book book1, Book book2) {
	return book1.getTitle() < book2.getTitle();
}

bool yearComparator(Book book1, Book book2) {
	return book1.getYear() > book2.getYear();
}

BookDatabase::BookDatabase(vector<Book> books)
{
	this->books = books;
}

void BookDatabase::fake_init()
{
	addBookToDatabase("To Kill a Mockingbird", "Harper Lee", 1960, 326, "");
	addBookToDatabase("Robinson Crusoe", "Daniel Defoe", 1719, 382, "");
	addBookToDatabase("Gone with the Wind", "Margaret Mitchell", 1936, 351, "");
	addBookToDatabase("Text pex shmeks", "Vilyam Zinsser", 1976, 288, "");
	addBookToDatabase("The Adventures of Tom Sawyer", "Mark Twain", 1876, 231, "");
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
	client->reservation.push_back(book->getBookInfo());
	book->addBookingElement(newBooking);
}

void BookDatabase::takeTheBook(Book* book, Client* client) {
	client->debts.push_back(book->getBookInfo());
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

vector<Book>& BookDatabase::getAllBooks()
{
	return books;
}

vector<Book>* BookDatabase::getAllBooksPointer()
{
	return &books;
}

vector<Book> BookDatabase::sortBooksByAuthor()
{
	vector<Book> new_books = books;
	sort(new_books.begin(), new_books.end(), authorComparator);
	return new_books;
}

vector<Book> BookDatabase::sortBooksByTitle()
{
	vector<Book> new_books = books;
	sort(new_books.begin(), new_books.end(), titleComparator);
	return new_books;
}

vector<Book> BookDatabase::sortBooksByYear()
{
	vector<Book> new_books = books;
	sort(new_books.begin(), new_books.end(), yearComparator);
	return new_books;
}