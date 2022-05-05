#include "pch.h"
#include "register.h"

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

bool passwordIsGood(std::string password, std::string confirmPass)
{
	while (password.length() < 8)
	{
		std::cout << "Password is too short!\n";
		return false;
	}
	while (!passwordHasNumbers(password))
	{
		std::cout << "Password needs to have numbers!\n";
		return false;
	}
	while (!passwordHasSymbols(password))
	{
		std::cout << "Password needs to have symbols(~`!@#$%^&*()_-+={[}]|:;\'<,>.?/\")!\n";
		return false;
	}
	while (password != confirmPass)
	{
		std::cout << "Password's don't match\n";
		return false;
	}
	return true;
}

void registerUser()
{
	int id = getLastId();
	std::string username, password, confirmPass;

	std::cin >> username >> password >> confirmPass;

	while (!passwordIsGood(password, confirmPass))
	{
		std::cin >> password;
		std::cin >> confirmPass;
	}
	//TODO: password = Call passwording hashing function(password)

	USER tempUser = { id, username, password };

	addUserInfo(tempUser);
}