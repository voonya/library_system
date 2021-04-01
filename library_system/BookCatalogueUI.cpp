#include "BookCatalogueUI.h"
#include "BookOutputter.h"
#include "BookProcessing.h"
#include "BooksProcessingMenu.h"
#include <iostream>

using namespace std;
void book_catalogue_ui::output_book_catalogue()
{
	cout << "Book catalogue:" << endl;
	book_outputter outputter;
	for (Book book : book_catalogue->getAllBooks())
	{
		outputter.output_book(book);
	}
}

void output_book_catalogue_no_database(vector<Book> books)
{
	cout << "Book catalogue:" << endl;
	book_outputter outputter;
	for (Book book : books)
	{
		outputter.output_book(book);
	}
}

book_catalogue_ui::book_catalogue_ui(BookDatabase* catalogue)
{
	book_catalogue = catalogue;
}

bool book_catalogue_ui::output_menu()
{
	cout << "Enter 1 to output the catalogue" << endl;
	cout << "Enter 2 to output the catalogue processing form" << endl;
	cout << "Enter 3 to quit this menu" << endl;
	int choice;
	cin >> choice;
	switch (choice)
	{
	case 1:
		output_book_catalogue();
		return output_menu();
	case 2:
		output_catalogue_processing_form();
		return output_menu();
	case 3:
		return false;
	default:
		cout << "Unknown choice!" << endl;
		return output_menu();
	}

	
}


void book_catalogue_ui::output_catalogue_processing_form()
{
	cout << "To sort the catalogue, enter 1" << endl <<
		"To edit/add/remove a book, enter 2" << endl;
	int answer;
	cin >> answer;
	if (answer == 1)
	{
		cout << "Choose sorting parameter (1 - title, 2 - author, 3 - year): ";
		int choice;
		cin >> choice;
		vector<Book> sorted;
		switch (choice)
		{
		case 1:
		{
			sorted = book_catalogue->sortBooksByTitle();
			cout << "Catalogue sorted!" << endl;
			output_book_catalogue_no_database(sorted);
			break;
		}
		case 2:
		{
			sorted = book_catalogue->sortBooksByAuthor();
			cout << "Catalogue sorted!" << endl;
			output_book_catalogue_no_database(sorted);
			break;
		}
		case 3:
		{
			sorted = book_catalogue->sortBooksByYear();
			cout << "Catalogue sorted!" << endl;
			output_book_catalogue_no_database(sorted);
			break;
		}
		default:
		{
			cout << "Unknown parameter" << endl;
		}
		}
	} else
	{
		BooksProcessingMenu processing;
		processing.startDialogMenu(*book_catalogue);
	}
}