#include "pch.h"
#include "login.h"

void loginUser(std::string username, std::string password)
{
	//TODO: Call password hashing function

	if (userExists(username, password))
	{
		addCurrentUser(username);
		return;
	}
}