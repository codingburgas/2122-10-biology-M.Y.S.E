#include "pch.h"
#include "login-files.h"

// Get current user from file
std::string getCurrentUser()
{
	std::ifstream currentUser("currentUser.txt");
	std::string line;
	getline(currentUser, line);

	return line;
}

// Add current user to file
void addCurrentUser(std::string username)
{
	std::ofstream currentUser("currentUser.txt", std::ios::trunc);

	currentUser << username << "\n";

	currentUser.close();
}

// Get user's Id
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

// Check if user is registered
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