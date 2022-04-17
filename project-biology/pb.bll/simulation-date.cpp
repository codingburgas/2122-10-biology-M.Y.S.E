#include "pch.h"
#include "simulation-date.h"

void switchDate(int& day, std::string& month)
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
    std::vector<int> days = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    int i = 0;
    while (i < 12)
    {
        if (days[i] == day && months[i] == month)
        {
            day = 0;
            if (i == 11)
            {
                month = months[0];
                break;
            }
            month = months[i + 1];
        }
        i++;
    }
    day++;
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