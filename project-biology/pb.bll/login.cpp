#include "pch.h"
#include "login.h"

// Login user
bool loginUser(std::string username, std::string password)
{
	password = sha256(password);

	if (userExists(username, password))
	{
		addCurrentUser(username);
		return true;
	}
	return false;
}