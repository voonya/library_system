#include <iostream>
#include "BooksProcessingMenu.h"

void BooksProcessingMenu::startDialogMenu(BookDatabase& DB)
{
	int number = 0;
	while (number != 5) {
		cout << "It's books processing menu\n";
		cout << "1 - to view books enter number\n";
		cout << "2 - to add new book enter number\n";
		cout << "3 - to edit existing book enter number\n";
		cout << "4 - to remove existing book enter number\n";
		cout << "5 - to exit from this menu enter number\n";
		cout << " Enter your answer: ";
		cin >> number;
		if (number == 1) {
			showBooks(DB);
		}
		if (number == 2) {
			string title, author, additionalInfo;
			int year, pages;
			cout << " Enter the title of book: ";
			cin.ignore();
			getline(cin, title);
			cout << " Enter the author of book: ";
			getline(cin, author);
			cout << " Enter created year of book: ";
			cin >> year;
			cout << " Enter number of pages of book: ";
			cin >> pages;
			cout << " Enter additional information about book: ";
			cin.ignore();
			getline(cin, additionalInfo);
			addNewBook(DB, title, author, year, pages, additionalInfo);
			cout << " New book successfully added!! \n";
		}
		if (number == 3) {
			int bookNumber;
			int result = request_book(bookNumber, DB);
			if (result == 1) {
				Book book = DB.getAllBooks()[bookNumber - 1];
				string newTitle = book.getTitle(),
					newAuthor = book.getAuthor(),
					newAdditionalInfo = book.getAdditionalInfo();
				int newPages = book.getPages(),
					newYear = book.getYear();
				int numb;
				cout << " 1 - to edit title of book\n";
				cout << " 2 - skip\n";
				cout << " Enter your answer: ";
				cin >> numb;
				cin.ignore();
				if (numb == 1) {
					cout << " Enter new title: ";
					getline(cin, newTitle);
				}
				cout << " 1 - to edit author of book\n";
				cout << " 2 - skip\n";
				cout << " Enter your answer: ";
				cin >> numb;
				cin.ignore();
				if (numb == 1) {
					cout << " Enter new author: ";
					getline(cin, newAuthor);
				}
				cout << " 1 - to edit created year of book\n";
				cout << " 2 - skip\n";
				cout << " Enter your answer: ";
				cin >> numb;
				cin.ignore();
				if (numb == 1) {
					cout << " Enter new year: ";
					cin >> newYear;
				}
				cout << " 1 - to edit number of pages of book\n";
				cout << " 2 - skip\n";
				cout << " Enter your answer: ";
				cin >> numb;
				cin.ignore();
				if (numb == 1) {
					cout << " Enter new number of pages: ";
					cin >> newPages;
				}
				cout << " 1 - to edit additional infornation of book\n";
				cout << " 2 - skip\n";
				cout << " Enter you answer: ";
				cin >> numb;
				cin.ignore();
				if (numb == 1) {
					cout << " Enter new additional information: ";
					getline(cin, newAdditionalInfo);
				}
				editBook(DB, bookNumber, newTitle, newAuthor, newYear, newPages, newAdditionalInfo);
				cout << " The book successfully updated!! \n";
			}
		}
		if (number == 4) {
			int bookNumber;
			int result = request_book(bookNumber, DB);
			if (result == 1) {
				removeBook(DB, bookNumber);
				cout << " The book successfully removed!! \n";
			}
		}
		if (number != 5) {
			cout << " 1 - to continue work with this menu\n";
			cout << " 5 - to exit from this menu enter number\n";
			cout << " Enter your answer: ";
			cin >> number;
		}
	}
}

// 1 - book found
// 0 - not found
// -1 - incorrect number
int BooksProcessingMenu::request_book(int &number, BookDatabase& DB)
{
	cout << " Enter the title of the book: ";
	string title;
	cin.ignore();
	getline(cin, title);
	vector<Book> found = DB.findByTitle(title);
	if (found.size() == 1)
	{
		number = DB.getBookNumber(found[0]) + 1;
	}
	else if (found.size() > 1)
	{
		cout << "There are several such books. Choose a number of the book you need" << endl;
		showBooks(found);
		cin >> number;
		if (number < 1 || number > found.size())
		{
			cout << "Incorrect book number!" << endl;
			return -1;
		}
		number = DB.getBookNumber(found[number - 1]) + 1;
	}
	else
	{
		cout << "Book not found!" << endl;
		return 0;
	}
	return  1;
}

void BooksProcessingMenu::showBooks(BookDatabase& DB)
{
	vector< Book > books = DB.getAllBooks();
	for (int i = 0; i < books.size(); i++) {
		string info = books[i].getBookInfo();
		cout << "------- " << i + 1 << " -------" << endl;
		cout << info << endl;
	}
}

void BooksProcessingMenu::showBooks(vector<Book> DB)
{
	vector< Book > books = DB;
	for (int i = 0; i < books.size(); i++) {
		string info = books[i].getBookInfo();
		cout << "------- " << i + 1 << " -------" << endl;
		cout << info << endl;
	}
}

void BooksProcessingMenu::addNewBook(BookDatabase& DB, string title, string author, int year, int pages, string additionalInfo)
{
	DB.addBookToDatabase(title, author, year, pages, additionalInfo);
}

void BooksProcessingMenu::editBook(BookDatabase& DB, int bookNumber, string newTitle, string newAuthor, int newYear, int newPages, string newAdditionalInfo)
{
	DB.editBook(&(DB.getAllBooks()[bookNumber - 1]), newTitle, newAuthor, newYear, newPages, newAdditionalInfo);
}

void BooksProcessingMenu::removeBook(BookDatabase& DB, int bookNumber)
{
	DB.removeBookFromDatabase(&(DB.getAllBooks()[bookNumber - 1]));
}