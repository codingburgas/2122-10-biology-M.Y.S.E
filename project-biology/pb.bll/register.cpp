#include "pch.h"
#include "register.h"

void registerUser()
{
	int id = file::getLastId();
	std::string fName, lName, username, password;

	std::cin >> fName >> lName >> username >> password;

	//TODO: password = Call passwording hashing function(password)

	USER tempUser = { id, fName, lName, username, password };

	file::addUserInfo(tempUser);
}