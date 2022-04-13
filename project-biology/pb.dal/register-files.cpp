#include "pch.h"
#include "../pb.dal/register-files.h"

void addUserInfo(USER user)
{
	std::ofstream userFile("userInfo.txt", std::ios::out | std::ios::app);

	std::string Id = std::to_string(user.id);
	std::string fName = user.fName;
	std::string lName = user.lName;
	std::string username = user.username;
	std::string password = user.password;

	if (userFile.is_open())
	{
		userFile << Id << ',';
		userFile << fName << ',';
		userFile << lName << ',';
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
		if (line.find("Id") != std::string::npos)
		{
			line = line.erase(0, 3);
			lastId = std::stoi(line) + 1;
		}
	}

	return lastId;
}