#pragma once
#include "ClientDatabase.h"
class LoginForm
{
public:
	int askUserType();
	int getUserIndex(ClientDatabase& DB, bool& found);
};

