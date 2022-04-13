#include "pch.h"
#include "register-files.h"

void addUserInfo(USER user)
{
	std::ofstream userFile("userInfo.txt", std::ios::out | std::ios::app);

	std::string Id = "Id:" + std::to_string(user.id);
	std::string fName = "FirstName:" + user.fName;
	std::string lName = "LastName:" + user.lName;
	std::string username = "Username:" + user.username;
	std::string password = "Password:" + user.password;

	if (userFile.is_open())
	{
		userFile << Id << '\n';
		userFile << fName << '\n';
		userFile << lName << '\n';
		userFile << username << '\n';
		userFile << password << '\n';
	}

	userFile.close();
}