#include "pch.h"
#include "login.h"

bool loginUser(std::string username, std::string password)
{
	// TODO: password = hash(password)

	if (userExists(username, password))
	{
		addCurrentUser(username);
		return true;
	}
	return false;
}