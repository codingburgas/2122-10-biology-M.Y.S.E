#pragma once

#include "pch.h"

struct USER
{
	int id = 0;
	std::string username = "";
	std::string password = "";
};

void addUserInfo(USER);
int getLastId();