#pragma once

#include "pch.h"

struct USER
{
	int id = 0;
	std::string fName = "";
	std::string lName = "";
	std::string username = "";
	std::string password = "";
};

void registerUser();