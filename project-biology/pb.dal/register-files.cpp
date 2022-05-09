#include "pch.h"
#include "../pb.dal/register-files.h"

// Add user info to file
void addUserInfo(USER user)
{
	std::ofstream userFile("../pb.dal/files/userInfo.txt", std::ios::out | std::ios::app);

	std::string Id = std::to_string(user.id);
	std::string username = user.username;
	std::string password = user.password;

	if (userFile.is_open())
	{
		userFile << Id << ',';
		userFile << username << ',';
		userFile << password << '\n';
	}

	userFile.close();
}

// Get last user Id
int getLastId()
{
	std::ifstream userFile("../pb.dal/files/userInfo.txt");

	if (!userFile.is_open())
	{
		return 1;
	}

	std::string line = "";
	int lastId = 1;

	while (getline(userFile, line))
	{
		lastId = std::stoi(line) + 1;
	}

	return lastId;
}