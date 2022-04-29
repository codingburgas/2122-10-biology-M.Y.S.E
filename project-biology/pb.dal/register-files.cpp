#include "pch.h"
#include "../pb.dal/register-files.h"

void addUserInfo(USER user)
{
	std::ofstream userFile("userInfo.txt", std::ios::out | std::ios::app);

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

int getLastId()
{
	std::ifstream userFile("userInfo.txt");

	if (!userFile.is_open())
	{
		return 0;
	}

	std::string line = "";
	int lastId = 0;

	while (getline(userFile, line))
	{
		lastId = std::stoi(line) + 1;
	}

	return lastId;
}