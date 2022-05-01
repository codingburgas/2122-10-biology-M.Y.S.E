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

void timer(unsigned short int& day, std::string& month, bool isPaused)
{
    using namespace std::literals::chrono_literals;
    switchDate(day, month);
    std::this_thread::sleep_for(0.01s);
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

int getTemperature(std::string month)
{
    srand(time(NULL) + rand());

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

    int monthIndex = getMonthsIndex(months, month);

    float temperature = 0;

    switch (monthIndex)
    {
    case 0: temperature = 4 - (rand() % 11); break;
    case 1: temperature = 10 - (rand() % 16); break;
    case 2: temperature = 14 - (rand() % 17); break;
    case 3: temperature = 18 - (rand() % 13); break;
    case 4: temperature = 13 - (rand() % 7); break;
    case 5: temperature = 34 - (rand() % 20); break;
    case 6: temperature = 34 - (rand() % 14); break;
    case 7: temperature = 35 - (rand() % 7); break;
    case 8: temperature = 32 - (rand() % 7); break;
    case 9: temperature = 25 - (rand() % 20); break;
    case 10: temperature = 13 - (rand() % 16); break;
    case 11: temperature = 7 - (rand() % 11); break;
    }

    temperature += ((rand() % 5) / 10);

    return temperature;
}