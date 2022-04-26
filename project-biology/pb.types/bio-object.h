#pragma once

#include "pch.h"

struct Object {
	std::string name;
	std::string information;
	std::string gender;
	float lifeExpInYears;
	std::vector<std::string> food;
	short int maxTemp;
	short int minTemp;
	unsigned short int hunger;
	float hungerRateByDays;
	unsigned short int maleCount;
	unsigned short int femaleCount;
	float pregnancy;
};