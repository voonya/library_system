#pragma once
#include <vector>
#include "BookDatabase.h"

using namespace std;
class book_catalogue_ui
{
private:
	BookDatabase book_catalogue;
public:
	bool output_menu();
	void output_book_catalogue();
	void output_catalogue_processing_form();
};