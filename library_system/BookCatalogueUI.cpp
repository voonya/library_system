#include "BookCatalogueUI.h"
#include "BookOutputter.h"
#include "BookProcessing.h"
#include <iostream>

using namespace std;
void book_catalogue_ui::output_book_catalogue()
{
	cout << "Book catalogue:" << endl;
	book_outputter outputter;
	for (Book book : book_catalogue.getAllBooks())
	{
		outputter.output_book(book);
	}
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
	cout << "Choose sorting parameter (1 - title, 2 - author, 3 - year): ";
	int choice;
	cin >> choice;
	BookProcessing processing;
	switch (choice)
	{
	case 1:
	case 2:
	case 3:
		processing.SortBookCatalogue(book_catalogue, choice);
		cout << "Catalogue sorted!" << endl;
		break;
	default:
		cout << "Unknown parameter" << endl;
	}
}