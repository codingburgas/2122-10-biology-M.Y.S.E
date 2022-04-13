#include "pch.h"
#include "login.h"

void loginUser()
{
	std::string username, password;
	std::cin >> username >> password;

	//TODO: Call password hashing function

	if (userExists(username, password))
	{
		std::cout << "You are logged in!\n";
		return;
	}
	std::cout << "There is no such user!\n";
}