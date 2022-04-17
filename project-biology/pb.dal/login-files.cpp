#include "pch.h"
#include "login-files.h"

int getId(std::string username, std::string password)
{
	std::ifstream userFile("userInfo.txt");
	std::string line;
	int id = 0;

	while (getline(userFile, line))
	{
		if (line.find(username) != std::string::npos)
		{
			if (line.find(password) != std::string::npos)
			{
				return id;
			}
		}
		id++;
	}
	return 0;
}

bool userExists(std::string username, std::string password)
{
	std::ifstream userFile("userInfo.txt");
	std::string line;

	while (getline(userFile, line))
	{
		if (line.find(username) != std::string::npos)
		{
			if (line.find(password) != std::string::npos)
			{
				return true;
			}
		}
	}
	return false;
}