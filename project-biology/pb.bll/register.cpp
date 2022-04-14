#include "pch.h"
#include "register.h"

bool passwordHasNumbers(std::string password)
{
	return (
		password.find('0') != std::string::npos ||
		password.find('1') != std::string::npos ||
		password.find('2') != std::string::npos ||
		password.find('3') != std::string::npos ||
		password.find('4') != std::string::npos ||
		password.find('5') != std::string::npos ||
		password.find('6') != std::string::npos ||
		password.find('7') != std::string::npos ||
		password.find('8') != std::string::npos ||
		password.find('9') != std::string::npos
		);
}

bool passwordHasSymbols(std::string password)
{
	return (
		password.find('~') != std::string::npos ||
		password.find('!') != std::string::npos ||
		password.find('@') != std::string::npos ||
		password.find('#') != std::string::npos ||
		password.find('$') != std::string::npos ||
		password.find('%') != std::string::npos ||
		password.find('^') != std::string::npos ||
		password.find('&') != std::string::npos ||
		password.find('*') != std::string::npos ||
		password.find('_') != std::string::npos ||
		password.find('-') != std::string::npos ||
		password.find('=') != std::string::npos ||
		password.find('+') != std::string::npos
		);
}

bool passwordIsGood(std::string password)
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
	return true;
}

void registerUser()
{
	int id = getLastId();
	std::string fName, lName, username, password;

	std::cin >> fName >> lName >> username >> password;

	while (!passwordIsGood(password))
		std::cin >> password;

	//TODO: password = Call passwording hashing function(password)

	USER tempUser = { id, fName, lName, username, password };

	addUserInfo(tempUser);
}