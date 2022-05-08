#include "pch.h"
#include "login-files.h"

std::string getCurrentUser()
{
	std::ifstream currentUser("currentUser.txt");
	std::string line;
	getline(currentUser, line);

	return line;
}

void addCurrentUser(std::string username)
{
	std::ofstream currentUser("currentUser.txt", std::ios::trunc);

	currentUser << username << "\n";

	currentUser.close();
}

int getId(std::string username, std::string password)
{
	std::ifstream userFile("../pb.dal/files/userInfo.txt");
	std::string line;
	int id = 0;

	while (getline(userFile, line))
	{
		id++;
		if (line.find(username) != std::string::npos)
		{
			if (line.find(password) != std::string::npos)
			{
				return id;
			}
		}
	}
	return 0;
}

bool userExists(std::string username, std::string password)
{
	std::ifstream userFile("../pb.dal/files/userInfo.txt");
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