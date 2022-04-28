#pragma once

#include "pch.h"

struct Object {
	std::string name;
	std::string information;
	std::string gender;
	float lifeExpInYears;
	float remainingDaysToDead;
	std::vector<std::string> food;
	short int maxTemp;
	short int minTemp;
	unsigned short int hunger;
	float hungerRateByDays;
	float pregnancy;
	float remainingDaysToGiveBirth;
};

struct CountObjects {
	unsigned short int maleCount;
	unsigned short int femaleCount;
};