#include "pch.h"
#include "logic-for-objects.h"
#include <stdlib.h>

void displayObjects(std::vector<Object> objectsInSimulation, std::vector<Object> objects, std::vector<CountObjects>& counterInSimulation, std::vector<bool> active, unsigned short int days, std::string mouth, std::string season, int temp)
{
	int count = 0;
	//for (int count = 0; count < objects.size() - 7; count++) {
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

	//}
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
std::vector<Object> removeObjectByHungerRateByDays(std::vector<Object> objectsInSimulation, unsigned short int days) {

	srand(time(NULL));

	bool whoWillDead = rand() % 1 + 1;

	for (int i = 0; i < objectsInSimulation.size(); i++) {
		//if (days % objectsInSimulation[i].lifeExpInWeeks * 7 == 0) {
			objectsInSimulation.erase(objectsInSimulation.begin() + i);

			if (objectsInSimulation[i].maleCount == 0) {
				--objectsInSimulation[i].femaleCount;
			}
			else if (objectsInSimulation[i].femaleCount == 0) {
				--objectsInSimulation[i].maleCount;
			}
			else {
				if (whoWillDead) {
					--objectsInSimulation[i].maleCount;
				}
				else {
					--objectsInSimulation[i].femaleCount;
				}
			}

		//}
	}

	return objectsInSimulation;
}

std::vector<Object> removeObjectByFood(std::vector<Object> objectsInSimulation, int i, unsigned short int days) {

	srand(time(NULL));

	int whoWillEat = rand() % 1 + 1;

	if (objectsInSimulation[i].maleCount == 0) {
		--objectsInSimulation[i].femaleCount;
	}
	else if (objectsInSimulation[i].femaleCount == 0) {
		--objectsInSimulation[i].maleCount;
	}
	else {
		if (whoWillEat) {
			--objectsInSimulation[i].maleCount;
		}
		else {
			--objectsInSimulation[i].femaleCount;
		}
	}

	if (objectsInSimulation[i].femaleCount == 0 && objectsInSimulation[i].maleCount == 0) {
		objectsInSimulation.erase(objectsInSimulation.begin() + i);
	}

	return objectsInSimulation;
}

std::vector<Object> removeObjectByLifeExpInWeeks(std::vector<Object> objectsInSimulation, unsigned short int days) {

	srand(time(NULL));

	bool whoWillDead = rand() % 1 + 1;

	for (int i = 0; i < objectsInSimulation.size(); i++) {
		//if (days % objectsInSimulation[i].lifeExpInWeeks * 7 == 0) {
			objectsInSimulation.erase(objectsInSimulation.begin() + i);

			if (objectsInSimulation[i].maleCount == 0) {
				--objectsInSimulation[i].femaleCount;
			}
			else if (objectsInSimulation[i].femaleCount == 0) {
				--objectsInSimulation[i].maleCount;
			}
			else {
				if (whoWillDead) {
					--objectsInSimulation[i].maleCount;
				}
				else {
					--objectsInSimulation[i].femaleCount;
				}
			}

		//}
	}

	return objectsInSimulation;
}
*/
std::vector<Object> startingAddObjectInSimulation(std::vector<Object> objectsInSimulation, std::vector<Object> objects, std::vector<CountObjects>& counterInSimulation, unsigned short int choice, unsigned short int days) {

	if (objects[choice].food.empty()) {
		counterInSimulation[choice].maleCount += 6;
		for (auto i = 0; i < 6; i++) {
			objectsInSimulation.push_back(objects[choice]);
		}
	}
	else {
		++counterInSimulation[choice].maleCount;
		++counterInSimulation[choice].femaleCount;
		for (auto i = 0; i < 2; i++) {
			if (objects[choice].gender != "Male")
				objects[choice].gender = "Male";
			else
				objects[choice].gender = "Female";

			objectsInSimulation.push_back(objects[choice]);
		}
	}

	return objectsInSimulation;
}

std::vector<Object> pregnancyObjectInSimulation(std::vector<Object> objectsInSimulation, std::vector<Object> objects, std::vector<CountObjects>& counterInSimulation)
{
	srand(time(NULL));
	int kids;
	bool gender, itIsPlant;
	float pregn;

	for (int i = 0; i < objects.size(); i++) {
		if (counterInSimulation[i].maleCount != 0) {
			if (objects[i].food.empty())
				itIsPlant = true;
			else
				itIsPlant = false;

			pregn = round(objectsInSimulation[i].pregnancy * 365);

			if (objectsInSimulation[i].remainingDaysToGiveBirth == pregn) {

				kids = rand() % 3 + 1;
				gender = rand() % 2;

				for (int j = 0; j < kids; j++) {
					if (gender == 0 || itIsPlant) {
						objects[i].gender = "Male";
						++counterInSimulation[i].maleCount;
					}
					else {
						objects[i].gender = "Female";
						++counterInSimulation[i].femaleCount;
					}

					objectsInSimulation.push_back(objects[i]);
				}

				objectsInSimulation[i].remainingDaysToGiveBirth = 0;
			}
			else {
				++objectsInSimulation[i].remainingDaysToGiveBirth;
			}
		}
	}

	return objectsInSimulation;
}

void simulation() {
	std::vector<Object> objects = infoObjects();
	std::vector<Object> objectsInSimulation;
	std::vector<CountObjects> counterInSimulation;

	counterInSimulation.resize(objects.size(), { 0, 0 });

	std::vector<bool> active;

	for (int i = 0; objects.size() - i > 0; i++) {
		active.push_back(false);
	}

	unsigned short int choice;
	unsigned short int days = 1, daysTimer = days;
	std::string mouth = "January";
	std::string season = "Winter";
	int tempeture = 1;

	while (true) {

		displayObjects(objectsInSimulation, objects, counterInSimulation, active, daysTimer, mouth, season, tempeture);

		++days;
		timer(daysTimer, mouth, false, choice);
		tempeture = getTemperature(mouth);
		season = getSeason(daysTimer, mouth);

		if (days == 2) {
			choice = 0;
			objectsInSimulation = startingAddObjectInSimulation(objectsInSimulation, objects, counterInSimulation, choice, days);
			active[choice] = true;
		}

		objectsInSimulation = pregnancyObjectInSimulation(objectsInSimulation, objects, counterInSimulation);

		/*
		for (int i = 0; i < objectsInSimulation.size(); i++) {

		}
		*/

		/*
		if (active[--choice] != true)
			active[choice] = true;
		else
			break;

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