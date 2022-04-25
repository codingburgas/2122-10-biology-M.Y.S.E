#pragma once

#include "pch.h"

struct Object {
	std::string name;
	//std::string gender;
	std::string information;
	std::size_t lifeExpInWeeks;
	std::vector<std::string> food;
	short int maxTemp;
	short int minTemp;
	unsigned short int hunger;
	float hungerRateByDays;
	unsigned short int maleCount;
	unsigned short int femaleCount;
	unsigned short int pregnancy;
};