#pragma once
#include "BookDatabase.h"
#include "Client_header.h"

struct Booking{
	Book* book;
	Client* client;
};