#include "pch.h"
#include "simulation-date.h"

void switchDate(unsigned short int& day, std::string& month)
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
    std::vector<unsigned short int> days = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

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

void timer(unsigned short int& day, std::string& month, bool isPaused, unsigned short int &choice)
{
    using namespace std::literals::chrono_literals;
    switchDate(day, month);
    std::this_thread::sleep_for(0.1s);
}

int getMonthsIndex(std::vector<std::string> months, std::string month)
{
    std::vector<std::string>::iterator it;
    it = std::find(months.begin(), months.end(), month);

    return std::distance(months.begin(), it);
}

std::string getSeason(unsigned short int day, std::string month)
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
    std::vector<unsigned short int> days = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    
    int dayNumber = 0;

    for (int i = 0; i < getMonthsIndex(months, month); i++)
    {
        dayNumber += days[i];
    }
    dayNumber += day;

    if (dayNumber >= 60 && dayNumber <= 151)
        return "Spring";
    if (dayNumber >= 152 && dayNumber <= 243)
        return "Summer";
    if (dayNumber >= 244 && dayNumber <= 334)
        return "Autumn";
    return "Winter";
}