#include "pch.h"
#include "login.h"

void loginUser(std::string username, std::string password)
{
	//TODO: Call password hashing function

	if (userExists(username, password))
	{
		std::cout << "You are logged in!\n";
		addCurrentUser(username);
		return;
	}
	std::cout << "There is no such user!\n";
}