#include "pch.h"
#include "logic-for-objects.h"
#include "../project-biology/front-to-back-end.h"
#include <stdlib.h>

void displayObjects(std::vector<Object> objectsInSimulation, std::vector<Object> objects, std::vector<CountObjects>& counterInSimulation, std::vector<unsigned short int> active, unsigned short int days, std::string mouth, std::string season, int temp)
{
	for (int count = 0; count < 6; count++) {
	std::cout << "Name: " << objects[count].name << "\n";
	//if (active[count] == 1) {
		//std::cout << "Live: " << objects[count].lifeExpInWeeks << "\n"; // How much time he leaves them to live
		//std::cout << "Hunger: " << objectsInSimulation[count].hungerRateByDays << "\n"; // How hungry they are
		//std::cout << "Weather: " << objects[count].lifeExpInWeeks << "\n"; // How it feels about the weather
		//std::cout << "Born: " << objectsInSimulation[count].pregnancy << "\n"; //     How much time is left for a new generation to be born
	if (objects[count].food.empty()) {
		std::cout << "Plants: " << counterInSimulation[count].maleCount << "\n\n";
	}
	else {
		std::cout << "Men: " << counterInSimulation[count].maleCount << "\n";
		std::cout << "Women: " << counterInSimulation[count].femaleCount << "\n\n";
	}

	}
	//else {
		//std::cout << "You can't see this information\n\n";
	//}
//}

	std::cout << "Days: " << days << std::endl;
	std::cout << "Mouth: " << mouth << std::endl;
	std::cout << "Season: " << season << "\n";
	std::cout << "Temperature: " << temp << "\n\n";
}
/*
bool removeObjectByHungerRateByDays(std::vector<Object>& objectsInSimulation, std::vector<Object> objects, std::vector<CountObjects>& counterInSimulation) {
	
	std::vector<Object>::iterator it;

	for (int i = 0; i < objectsInSimulation.size(); i++) {
		if (!(objectsInSimulation[i].food.empty())) {
			for (int j = 0; j < objectsInSimulation[i].food.size(); j++)
			{
				it = std::find(objectsInSimulation.begin(), objectsInSimulation.end(), objectsInSimulation[i].food[j]);
				if (it == objectsInSimulation.end()) {

				}
			}
			
		}
	}

}

void removeObjectByFood(std::vector<Object>& objectsInSimulation, std::vector<Object> objects, std::vector<CountObjects>& counterInSimulation) {
	std::vector<Object>::iterator it;

	for (int i = 0; i < objectsInSimulation.size(); i++) {
		if (!(objectsInSimulation[i].food.empty())) {
			for (int j = 0; j < objectsInSimulation[i].food.size(); j++) {
				it = std::find(objectsInSimulation.begin(), objectsInSimulation.end(), objectsInSimulation[i].food[j]);
				for (int m = 0; m < objectsInSimulation.size(); m++)
				{
					if (it != objectsInSimulation.end() && objectsInSimulation[i].food[j] == objectsInSimulation[m].name) {
						if (objectsInSimulation[i].gender == "Male")
							--counterInSimulation[j].maleCount;
						else
							--counterInSimulation[j].femaleCount;

						++counterInSimulation[j].deadCount;

						objectsInSimulation.erase(objectsInSimulation.begin() + m);
					}
				}
			}
		}
	}
}
*/
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

void startingAddObjectInSimulation(std::vector<Object> &objectsInSimulation, std::vector<Object> objects, std::vector<CountObjects>& counterInSimulation, size_t choice, unsigned short int days) {

	if (objects[choice].food.empty()) {
		counterInSimulation[choice].maleCount += 6;
		for (auto i = 0; i < 6; i++) {
			objectsInSimulation.push_back(objects[choice]);
		}
	}
	else {
		for (auto i = 0; i < 20; i++) {
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

void time(unsigned short& days, unsigned short& daysTimer, std::string& mouth, size_t& choice, int& tempeture, std::string& season)
{

	++days;
	timer(daysTimer, mouth, false, choice);
	tempeture = getTemperature(mouth);
	season = getSeason(daysTimer, mouth);
}

std::vector<Object> logicSimulation(std::vector<Object> objectsInSimulation, std::vector<Object> objects, std::vector<CountObjects>& counterInSimulation, std::vector<unsigned short int> &active, size_t choice, unsigned short int days, int &temp)
{
	
	for (int i = 0; i < objects.size(); i++) {
		if (active[i] == 1) {
			startingAddObjectInSimulation(objectsInSimulation, objects, counterInSimulation, choice, days);
			active[i] = 2;
		}
	}

	pregnancyObjectInSimulation(objectsInSimulation, objects, counterInSimulation);
	removeObjectByLifeExpInYears(objectsInSimulation, objects, counterInSimulation);
	removeObjectByTempeture(objectsInSimulation, objects, counterInSimulation, temp);

	return objectsInSimulation;
}

void simulation() {
	std::vector<Object> objects = infoObjects();
	std::vector<Object> objectsInSimulation;
	std::vector<CountObjects> counterInSimulation;
	std::vector<unsigned short int> active;

	counterInSimulation.resize(objects.size(), { 0, 0, 0});

	for (int i = 0; i < objects.size(); i++) {
		active.push_back(0);
	}

	size_t choice = -1;
	bool start = true;
	unsigned short int days = 1, daysTimer = days;
	std::string mouth = "January";
	std::string season = "Winter";
	int tempeture = 1;

	while (start) {
		
		displayObjects(objectsInSimulation, objects, counterInSimulation, active, daysTimer, mouth, season, tempeture);
		time(days, daysTimer, mouth, choice, tempeture, season);

		
		//choice = getId(choice);
		//active[choice] = 1;

		if (choice != 5) {
			++choice;
			active[choice] = 1;
		}


		objectsInSimulation = logicSimulation(objectsInSimulation, objects, counterInSimulation, active, choice, days, tempeture);

		/*
		for (auto i = 0; i < objectsInSimulation.size(); i++) {
				for (auto j = 0; j < objectsInSimulation.size(); j++) {
					for (auto k = 0; k < objects[j].food.size(); k++) {
						for (auto m = 0; m < objectsInSimulation.size(); m++) {
							if (!(objectsInSimulation[i].name == objects[j].name && objects[j].food.size() == 0)) {
								if (objectsInSimulation[i].name == objects[j].name && objects[j].food[k] == objectsInSimulation[m].name) {
									removeObject(objectsInSimulation, j);
								}
							}
							else {
								removeObject(objectsInSimulation, i);
								break;
							}
						}
					}
				}
			}
			*/
		system("CLS");
	}
}