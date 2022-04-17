#include "pch.h"
#include "simulation-date.h"

int getIndex(std::string month)
{
	std::vector<std::string> months = {
		"January",
		"February",
		"March",
		"April",
		"May",
		"June",
		"July",
		"August",
		"September",
		"October",
		"November",
		"December"
	};

	std::vector<std::string>::iterator it;
	it = std::find(months.begin(), months.end(), month);

	return std::distance(months.begin(), it);
}

void switchDate(int& day, std::string& month)
{
	int monthNumber = getIndex(month);

	switch (monthNumber)
	{
	case 0: 
		if (day == 31)
		{
			day = 0;
			month = "February";
		}
		day++;
		break;
	case 1: 
		if (day == 28)
		{
			day = 0;
			month = "March";
		}
		day++;
		break;
	case 2:
		if (day == 31)
		{
			day = 0;
			month = "April";
		}
		day++;
		break;
	case 3:
		if (day == 30)
		{
			day = 0;
			month = "May";
		}
		day++;
		break;
	case 4:
		if (day == 31)
		{
			day = 0;
			month = "June";
		}
		day++;
		break;
	case 5:
		if (day == 30)
		{
			day = 0;
			month = "July";
		}
		day++;
		break;
	case 6:
		if (day == 31)
		{
			day = 0;
			month = "August";
		}
		day++;
		break;
	case 7:
		if (day == 31)
		{
			day = 0;
			month = "September";
		}
		day++;
		break;
	case 8:
		if (day == 30)
		{
			day = 0;
			month = "October";
		}
		day++;
		break;
	case 9:
		if (day == 31)
		{
			day = 0;
			month = "November";
		}
		day++;
		break;
	case 10:
		if (day == 30)
		{
			day = 0;
			month = "December";
		}
		day++;
		break;
	case 11:
		if (day == 31)
		{
			day = 0;
			month = "January";
		}
		day++;
		break;
	}
}

void timer(int& day, std::string& month)
{
	using namespace std::literals::chrono_literals;

	while (true)
	{
		switchDate(day, month);

		std::this_thread::sleep_for(5s);
	}
}