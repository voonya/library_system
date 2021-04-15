#pragma once
#include <string>
#include <queue>
#include "Booking.h"

using namespace std;

class Book {
	int id;
	string title;
	string author;
	int year;
	int pages;
	string additionalInfo;
	queue< Booking > bookingQueue;
public: 
	Book(int ID, string t, string auth, int y, int p, string addInfo, queue< Booking > _queue);
	int getId();
	bool operator==(Book book);
	string getTitle();
	void setTitle(string newTitle);
	string getAuthor();
	void setAuthor(string newAuthor);
	int getYear();
	void setYear(int newYear);
	int getPages();
	void setPages(int newPages);
	string getAdditionalInfo();
	void setAdditionalInfo(string newAdditionalInfo);
	queue< Booking > getBookingQueue();
	void addBookingElement(Booking elem);
	string getBookInfo();
	string getAllBookInfo();
	friend class book_outputter;
};