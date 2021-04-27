#pragma once
#include <vector>
#include "../../Databases/BookDatabase.h"

using namespace std;
class book_catalogue_ui
{
private:
	BookDatabase* book_catalogue;
public:
	book_catalogue_ui(BookDatabase* catalogue);
	bool output_menu();
	void output_book_catalogue();
	void output_catalogue_processing_form();
};