#pragma once
#include <vector>
#include "../../Databases/ClientDatabase.h"

using namespace std;
class ClientCatalogueUI
{
private:
	ClientDatabase* client_catalogue;
public:
	ClientCatalogueUI(ClientDatabase* database);
	bool output_menu();
	void output_client_catalogue();
	void output_catalogue_processing_form();
};

