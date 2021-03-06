#include <queue>
#include "Book.h"

Book::Book(int ID, string t, string auth, int y, int p, string addInfo, queue< Booking > _queue) : id(ID), title(t), author(auth), year(y), pages(p), additionalInfo(addInfo), bookingQueue(_queue) {};

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

queue< Booking > Book::getBookingQueue() {
	return bookingQueue;
}

void Book::addBookingElement(Booking elem) {
	bookingQueue.push(elem);
}


string Book::getBookInfo()
{
	string str = "\n Title: " + title + "\n Author: " + author + "\n Year: " + to_string(year) + "\n Number pages: " + to_string(pages);
	str += "\n Booking: ";
	queue< Booking > _queue = bookingQueue;
	while (!_queue.empty()) {
		str += "\n---------\n" + get_name_sur(*_queue.front().client) + "\n---------";
		_queue.pop();
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
