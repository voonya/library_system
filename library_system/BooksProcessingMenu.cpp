#include <iostream>
#include "BooksProcessingMenu.h"

void BooksProcessingMenu::startDialogMenu(BookDatabase& DB)
{
	int number = 0;
	while (number != 5) {
		cout << "It's books propcessing menu\n";
		cout << "To view books enter number '1'\n";
		cout << "To add new book enter number '2'\n";
		cout << "To edit existing book enter number '3'\n";
		cout << "To remove existing book enter number '4'\n";
		cout << "To exit from this menu enter number '5'\n";
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
			cout << " Enter book number to edit it: ";
			cin >> bookNumber;
			if (bookNumber >= 1 && bookNumber <= DB.getAllBooks().size()) {
				Book book = DB.getAllBooks()[bookNumber - 1];
				string newTitle = book.getTitle(),
					newAuthor = book.getAuthor(),
					newAdditionalInfo = book.getAdditionalInfo();
				int newPages = book.getPages(),
					newYear = book.getYear();
				int numb;
				cout << " To edit title of book enter '1' else enter '2'\n";
				cout << " Enter your answer: ";
				cin >> numb;
				if (numb == 1) {
					cout << " Enter new title: ";
					getline(cin, newTitle);
				}
				cout << " To edit author of book enter '1' else enter '2' \n";
				cout << " Enter your answer: ";
				cin >> numb;
				if (numb == 1) {
					cout << " Enter new author: ";
					getline(cin, newAuthor);
				}
				cout << " To edit created year of book enter '1' else enter '2' \n";
				cout << " Enter your answer: ";
				cin >> numb;
				if (numb == 1) {
					cout << " Enter new year: ";
					cin >> newYear;
				}
				cout << " To edit number of pages of book enter '1' else enter '2' \n";
				cout << " Enter your answer: ";
				cin >> numb;
				if (numb == 1) {
					cout << " Enter new number of pages: ";
					cin >> newPages;
				}
				cout << " To edit additional infornation of book enter '1' else enter '2' \n";
				cout << " Enter you answer: ";
				cin >> numb;
				if (numb == 1) {
					cout << " Enter new additional information: ";
					getline(cin, newAdditionalInfo);
				}
				editBook(DB, bookNumber, newTitle, newAuthor, newYear, newPages, newAdditionalInfo);
				cout << " The book successfully updated!! \n";
			}
			else {
				cout << " Incorrect book number!! \n";
			}
		}
		if (number == 4) {
			int bookNumber;
			cout << " Enter book number to remove it: ";
			cin >> bookNumber;
			if (bookNumber <= 0 || bookNumber > DB.getAllBooks().size()) {
				cout << " Incorrect book number!! \n";
			}
			else {
				removeBook(DB, bookNumber);
				cout << " The book successfully removed!! \n";
			}
		}
		if (number != 5) {
			cout << " To continue work with this menu enter '1' \n";
			cout << " To exit from this menu enter number '5'\n";
			cout << " Enter your answer: ";
			cin >> number;
		}
	}
}

void BooksProcessingMenu::showBooks(BookDatabase& DB)
{
	vector< Book > books = DB.getAllBooks();
	for (int i = 0; i < books.size(); i++) {
		string info = books[i].getBookInfo();
		cout << "------- " << i + 1 << " -------";
		cout << info << endl;
	}
}

void BooksProcessingMenu::addNewBook(BookDatabase& DB, string title, string author, int year, int pages, string additionalInfo)
{
	DB.addBookToDatabase(title, author, year, pages, additionalInfo);
}

void BooksProcessingMenu::editBook(BookDatabase& DB, int bookNumber, string newTitle, string newAuthor, int newYear, int newPages, string newAdditionalInfo)
{
	DB.editBook((&DB.getAllBooks()[bookNumber - 1]), newTitle, newAuthor, newYear, newPages, newAdditionalInfo);
}

void BooksProcessingMenu::removeBook(BookDatabase& DB, int bookNumber)
{
	DB.removeBookFromDatabase((&DB.getAllBooks()[bookNumber - 1]));
}