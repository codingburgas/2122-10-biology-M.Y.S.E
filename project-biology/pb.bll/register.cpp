#include "pch.h"
#include "register.h"

// Check if password has numbers
bool passwordHasNumbers(std::string password)
{
	bool flag = false;

	for (int i = 48; i <= 57; i++)
	{
		if (password.find(char(i)) != std::string::npos)
			flag = true;
	}

	return flag;
}

// Check if password has symbols
bool passwordHasSymbols(std::string password)
{
	bool flag = false;

	for (int i = 33; i <= 47; i++)
	{
		if (password.find(char(i)) != std::string::npos)
			flag = true;
	}

	return flag;
}

// Check if all password requirements are met
int passwordIsGood(std::string password, std::string confirmPass)
{
	while (password.length() < 8)
	{
		std::cout << "Password is too short!\n";
		return 1;
	}
	while (!passwordHasNumbers(password))
	{
		std::cout << "Password needs to have numbers!\n";
		return 2;
	}
	while (!passwordHasSymbols(password))
	{
		std::cout << "Password needs to have symbols(~`!@#$%^&*()_-+={[}]|:;\'<,>.?/\")!\n";
		return 3;
	}
	while (password != confirmPass)
	{
		std::cout << "Password's don't match\n";
		return 4;
	}
	return 0;
}

// Register user
int registerUser(std::string username, std::string password, std::string confirmPass)
{
	int id = getLastId();

	if (passwordIsGood(password, confirmPass) == 0)
	{
		password = sha256(password);

		USER tempUser = { id, username, password };

		addUserInfo(tempUser);
		addCurrentUser(username);
		return 0;
	}

	return passwordIsGood(password, confirmPass);
}