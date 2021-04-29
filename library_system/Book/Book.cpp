#include <queue>
#include "Book.h"

Book::Book(int ID, string t, string auth, int y, int p, string addInfo, vector< Booking > _queue) : id(ID), title(t), author(auth), year(y), pages(p), additionalInfo(addInfo), bookingQueue(_queue) {};

int Book::getId() {
	return id;
}

string Book::getTitle() {
	return title;
}

void Book::setTitle(string newTitle) {
	title = newTitle;
}

string Book::getAuthor() {
	return author;
}

void Book::setAuthor(string newAuthor) {
	author = newAuthor;
}

int Book::getYear() {
	return year;
}

void Book::setYear(int newYear) {
	year = newYear;
}

int Book::getPages() {
	return pages;
}

void Book::setPages(int newPages) {
	if (newPages > 0)
		pages = newPages;
}

string Book::getAdditionalInfo() {
	return additionalInfo;
}

void Book::setAdditionalInfo(string newAdditionalInfo) {
	additionalInfo = newAdditionalInfo;
}

vector< Booking > Book::getBookingQueue() {
	return bookingQueue;
}

void Book::addBookingElement(Booking elem) {
	bookingQueue.push_back(elem);
}


string Book::getBookInfo()
{
	string str = "\n Title: " + title + "\n Author: " + author + "\n Year: " + to_string(year) + "\n Number pages: " + to_string(pages);
	str += "\n Booking: ";
	for (int i = 0; i < bookingQueue.size(); i++) {
		str += "\n---------\n" + get_name_sur(*bookingQueue[i].client) + "\n---------";
	}
	return str;
}

bool Book::operator==(Book book)
{
	return book.getId() == id;
}

string Book::getAllBookInfo()
{
	string str = "Title: " + title + "\nAuthor: " + author + "\nYear: " + to_string(year) + "\nNumber pages: " + to_string(pages) +
		"\nAdditional info: " + additionalInfo;
	return str;
}

void Book::removeTopBooking()
{
	if (bookingQueue.size())
		bookingQueue.erase(bookingQueue.end() - 1);
}