#include "pch.h"
#include "logic-for-objects.h"
#include "../project-biology/front-to-back-end.h"

unsigned short int sumOfPopulation(std::vector<CountObjects> counterInSimulation, int key)
{
	return counterInSimulation[key].femaleCount + counterInSimulation[key].maleCount;
}

std::vector<std::string> objectFeelingByHunger(std::vector<Object> objects, std::vector<CountObjects>& counterInSimulation)
{
	std::vector<std::string> feeling;

	unsigned short int firstPopulation = 0;
	unsigned short int secondPopulation = 0;
	unsigned short int helper;

	for (int i = 0; i < objects.size(); i++)
	{
		if (!(objects[i].food.empty())) {
			firstPopulation = sumOfPopulation(counterInSimulation, i);

			for (int j = 0; j < objects.size(); j++)
			{
				if (objects[i].food[0] == objects[j].name)
				{
					secondPopulation = sumOfPopulation(counterInSimulation, j);
					break;
				}
			}

			helper = firstPopulation * 2;
			if (firstPopulation < secondPopulation && helper < secondPopulation) {
				feeling.push_back("satisfied");
			}
			else {
				if (firstPopulation < secondPopulation) {
					feeling.push_back("well");
				}
				else {
					helper = firstPopulation / 2;
					if (firstPopulation > secondPopulation && secondPopulation > helper) {
						feeling.push_back("hungry");
					}
					else {
						feeling.push_back("too hungry");
					}
				}
			}
		}
	}

	return feeling;
}

std::vector<std::string> objectFeelingByTempeture(std::vector<Object> objects, int temp)
{
	std::vector<std::string> feeling;
	int sum, helper;
	bool isWarm = false;

	for (int i = 0; i < objects.size(); i++)
	{
		sum = (objects[i].maxTemp + objects[i].minTemp) / 2;

		if (objects[i].maxTemp < temp) {
			feeling.push_back("too hot");
		}
		else {
			if (temp > sum) {
				feeling.push_back("warm");
			}
			else {
				for (int i = 2; i >= -2; i--) {
					if (temp == sum + 2)
						isWarm = true;
				}
				
				if (isWarm) {
					feeling.push_back("well");
				}
				else {
					if (sum > temp && temp > objects[i].minTemp) {
						feeling.push_back("cold");
					}
					else {
						feeling.push_back("too hot");
					}
				}

			}
		}
	}

	return feeling;
}

void removeObjectByFood(std::vector<Object>& objectsInSimulation, std::vector<Object> objects, std::vector<CountObjects>& counterInSimulation) {

	std::vector<bool> eat;
	bool breakAll = false;
	eat.resize(objectsInSimulation.size(), { 0 });

	for (int i = 0; i < objectsInSimulation.size(); i++)
	{
		if (!(objectsInSimulation[i].food.empty()))
		{
			for (int j = 0; j < 1; j++)
			{
				for (int m = 0; m < objectsInSimulation.size(); m++)
				{
					for (int k = 0; k < objects.size(); k++)
					{
						if (!(objectsInSimulation[i].food.empty()))
						{
							if (objectsInSimulation[i].food[j] == objectsInSimulation[m].name && objectsInSimulation[m].name == objects[k].name)
							{
								eat[i] = true;

								objectsInSimulation[i].hungerRateByDays = 0;

								if (objectsInSimulation[m].gender == "Male")
									--counterInSimulation[k].maleCount;
								else
									--counterInSimulation[k].femaleCount;
								++counterInSimulation[k].deadCount;

								objectsInSimulation.erase(objectsInSimulation.begin() + m);

								if (i == objectsInSimulation.size() || m == objectsInSimulation.size())
									breakAll = true;
							}
						}
						if (i == objectsInSimulation.size() || m == objectsInSimulation.size())
							breakAll = true;

						if (eat[i] || breakAll)
							break;

					}

					if (eat[i] || breakAll)
						break;
				}

				if (eat[i] || breakAll)
					break;

				if (!(eat[i])) {
					++objectsInSimulation[i].hungerRateByDays;
				}

				for (int k = 0; k < objects.size(); k++)
				{
					if (!(i == objectsInSimulation.size())) {
						if (!(objectsInSimulation[i].food.empty())) {
							if (objectsInSimulation[i].hungerRateByDays == objectsInSimulation[i].hunger && objectsInSimulation[i].name == objects[k].name) {

								if (objectsInSimulation[i].gender == "Male")
									--counterInSimulation[k].maleCount;
								else
									--counterInSimulation[k].femaleCount;

								++counterInSimulation[k].deadCount;
								objectsInSimulation[i].hungerRateByDays = 0;

								objectsInSimulation.erase(objectsInSimulation.begin() + i);

								if (i == objectsInSimulation.size())
									breakAll = true;
							}
						}
					}
					else {
						break;
					}
				}
			}

			if (breakAll)
				break;

		}

		if (breakAll)
			break;
	}
}

void removeObjectByLifeExpInYears(std::vector<Object>& objectsInSimulation, std::vector<Object> objects, std::vector<CountObjects>& counterInSimulation)
{
	float life;

	for (int i = 0; i < objectsInSimulation.size(); i++) {
		for (int j = 0; j < objects.size(); j++) {

			if (objectsInSimulation[i].name == objects[j].name) {

				life = round(objectsInSimulation[i].lifeExpInYears * 365);

				if (life == objectsInSimulation[i].remainingDaysToDead) {

					if (objectsInSimulation[i].gender == "Male")
						--counterInSimulation[j].maleCount;
					else
						--counterInSimulation[j].femaleCount;

					++counterInSimulation[j].deadCount;

					objectsInSimulation.erase(objectsInSimulation.begin() + i);
				}
				else {
					++objectsInSimulation[i].remainingDaysToDead;
				}
			}
		}
	}
}

void removeObjectByTempeture(std::vector<Object>& objectsInSimulation, std::vector<Object> objects, std::vector<CountObjects>& counterInSimulation, int temp)
{
	std::vector<std::string> deadObjects;
	bool rip = true;
	srand(time(NULL));
	int willDead;

	for (int i = 0; i < objectsInSimulation.size(); i++) {
		if (!(objectsInSimulation[i].food.empty())) {
			for (int j = 0; j < objects.size(); j++) {
				if (!(objectsInSimulation.empty())) {
					if (temp > objectsInSimulation[i].maxTemp || temp < objectsInSimulation[i].minTemp) {
						for (int m = 0; m < deadObjects.size(); m++) {
							if (objectsInSimulation[i].name == deadObjects[m])
								rip = false;
						}

						if (objects[j].name == objectsInSimulation[i].name) {
							if (counterInSimulation[j].maleCount > 6) {
								if (rip) {
									willDead = rand() % 3 + 1;
									if (willDead == 1) {
										if (objectsInSimulation[i].gender == "Male")
											--counterInSimulation[j].maleCount;
										else
											--counterInSimulation[j].femaleCount;

										++counterInSimulation[j].deadCount;

										deadObjects.push_back(objectsInSimulation[i].name);
										objectsInSimulation.erase(objectsInSimulation.begin() + i);
									}
								}
							}
							rip = true;
						}
					}
				}
			}
		}
	}

}

void startingAddObjectInSimulation(std::vector<Object>& objectsInSimulation, std::vector<Object> objects, std::vector<CountObjects>& counterInSimulation, short int choice, unsigned short int days) {



	if (objects[choice].food.empty()) {
		if (objects[choice].name == "Grass")
			counterInSimulation[choice].maleCount += 20;
		else
			counterInSimulation[choice].maleCount += 10;

		objects[choice].gender = "Male";

		for (auto i = 0; i < counterInSimulation[choice].maleCount; i++) {
			objectsInSimulation.push_back(objects[choice]);
		}
	}
	else {
		for (auto i = 0; i < 2; i++) {
			if (objects[choice].gender != "Male") {
				objects[choice].gender = "Male";
				++counterInSimulation[choice].maleCount;
			}
			else {
				objects[choice].gender = "Female";
				++counterInSimulation[choice].femaleCount;
			}

			objectsInSimulation.push_back(objects[choice]);
		}
	}
}

void pregnancyObjectInSimulation(std::vector<Object>& objectsInSimulation, std::vector<Object> objects, std::vector<CountObjects>& counterInSimulation)
{
	srand(time(NULL));
	int kids;
	bool Gender, itIsPlant;
	float pregn;

	for (int i = 0; i < objectsInSimulation.size(); i++) {
		for (int j = 0; j < objects.size(); j++) {
			if (objectsInSimulation[i].name == objects[j].name) {
				if (counterInSimulation[j].maleCount != 0) {
					if (objectsInSimulation[i].food.empty())
						itIsPlant = true;
					else
						itIsPlant = false;

					pregn = round(objectsInSimulation[i].pregnancy * 365);

					if (objectsInSimulation[i].remainingDaysToGiveBirth == pregn) {

						if (!(itIsPlant)) {
							kids = rand() % 3 + 1;
							Gender = rand() % 2;
						}
						else {
							kids = 1;
							Gender = false;
						}

						for (int m = 0; m < kids; m++) {
							if (Gender == false) {
								objects[j].gender = "Male";
								++counterInSimulation[j].maleCount;
							}
							else {
								objects[j].gender = "Female";
								++counterInSimulation[j].femaleCount;
							}

							objectsInSimulation.push_back(objects[j]);
						}

						objectsInSimulation[i].remainingDaysToGiveBirth = 0;
					}
					else {
						++objectsInSimulation[i].remainingDaysToGiveBirth;
					}
				}
			}
		}
	}

}

void time(unsigned short int& days, std::string& month, std::string& season, int& temp)
{
	timer(days, month, false);
	temp = getTemperature(month);
	season = getSeason(days, month);
}

std::vector<Object> logicSimulation(std::vector<Object> objectsInSimulation, std::vector<Object> objects, std::vector<CountObjects>& counterInSimulation, short int choice, unsigned short int days, int& temp, bool start)
{

	for (int i = 0; i < objects.size(); i++) {
		if (choice != -1) {
			startingAddObjectInSimulation(objectsInSimulation, objects, counterInSimulation, choice, days);
		}
	}
	
	if (start) {
		pregnancyObjectInSimulation(objectsInSimulation, objects, counterInSimulation);
		removeObjectByLifeExpInYears(objectsInSimulation, objects, counterInSimulation);
		removeObjectByTempeture(objectsInSimulation, objects, counterInSimulation, temp);
		removeObjectByFood(objectsInSimulation, objects, counterInSimulation);
	}

	return objectsInSimulation;
}

void simulation(bool &start, bool &backEndRun) {

	std::string textTime;
	unsigned short int days;
	std::string month;
	std::string season;
	int temp, i = 0, j = 0;

	std::fstream timeFile;
	timeFile.open("../pb.dal/files/time.txt");

	while (getline(timeFile, textTime, '|')) {
		switch (i) {
			case 0: days = stoi(textTime); break;
			case 1: month = textTime; break;
			case 2: season = textTime; break;
			case 3: temp = stoi(textTime); break;
		}
		++i;
	}

	textTime = "";

	timeFile.close();

	std::vector<short int> choices;
	short int choice = -1;
	std::vector<Object> objects = infoObjects();
	std::vector<Object> objectsInSimulation;
	std::vector<CountObjects> counterInSimulation;

	counterInSimulation.resize(objects.size(), { 0, 0, 0 });

	std::ifstream choiceFile("../pb.dal/files/choice.txt", std::fstream::out | std::fstream::trunc);

	getline(choiceFile, textTime);
	if(textTime != "")
		choice = stoi(textTime);

	choiceFile.close();
	
	if (choice != -1) {
		std::fstream choicesFile("../pb.dal/files/choices.txt", std::ios::in);

		bool flag = true;

		while(getline(choicesFile, textTime, '|'))
			if(stoi(textTime) == choice)
				flag = false;

		choicesFile.close();
		choicesFile.open("../pb.dal/files/choices.txt", std::ios::out);

		if (flag)
		{
			choicesFile << choice << '|';
		}

		/*while (getline(choicesFile, textTime, '|'))
		{
			choices.push_back(stoi(textTime));
		}

		choicesFile.close();
		choicesFile.open("../pb.dal/files/choices.txt", std::ios::out);

		if (std::find(choices.begin(), choices.end(), choice) != choices.end())
		{
			choices.push_back(choice);
			choicesFile << choice << '|';
		}
		else
		{
			choice = -1;
		}*/

		choicesFile.close();
	}

	objectsInSimulation = logicSimulation(objectsInSimulation, objects, counterInSimulation, choice, days, temp, start);
	choice = -1;

	if (start) 
	{

		time(days, month, season, temp);

		timeFile.open("../pb.dal/files/time.txt", std::fstream::out | std::fstream::trunc);

		timeFile << days << "|";
		timeFile << month << "|";
		timeFile << season << "|";
		timeFile << temp;

		timeFile.close();

		
		saveSimulationToFile(objectsInSimulation, counterInSimulation, objects);

		backEndRun = true;
	}
}