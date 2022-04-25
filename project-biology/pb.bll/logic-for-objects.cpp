#include "pch.h"
#include "logic-for-objects.h"
#include <stdlib.h>

void displayObjects(std::vector<Object> objectsInSimulation, std::vector<Object> objects, std::vector<bool> active, unsigned short int days, std::string mouth, std::string season)
{

		for (int count = 0; count < objects.size(); count++) {
			std::cout << "Name: " << objects[count].name << "\n";
			if (active[count] == 1) {
				std::cout << "Live: " << objects[count].lifeExpInWeeks << "\n"; // How much time he leaves them to live
				std::cout << "Hunger: " << objects[count].hungerRateByDays << "\n"; // How hungry they are
				//std::cout << "Weather: " << objects[count].lifeExpInWeeks << "\n"; // How it feels about the weather
				//std::cout << "Born: " << objects[count].pregnancy << "\n"; //     How much time is left for a new generation to be born
				if (objects[count].food.empty()) {
					std::cout << "Plants: " << objects[count].maleCount << "\n\n";
				}
				else {
					std::cout << "Men: " << objects[count].maleCount << "\n";
					std::cout << "Women: " << objects[count].femaleCount << "\n\n";
				}
				
			}
			else {
				std::cout << "You can't see this information\n\n";
			}
		}

		std::cout << "Days: " << days << std::endl;
		std::cout << "Mouth: " << mouth << std::endl;
		std::cout << "Season: " << season << "\n\n";

		for (int i = 0; i < 4; i++) {
			if (active[i] == false) {
				std::cout << i + 1 << ".";
				std::cout << objects[i].name;
				std::cout << " ";
			}
		}
}

std::vector<Object> removeObjectByHungerRateByDays(std::vector<Object> objectsInSimulation, unsigned short int days) {

	srand(time(NULL));

	bool whoWillDead = rand() % 1 + 1;

	for (int i = 0; i < objectsInSimulation.size(); i++) {
		if (days % objectsInSimulation[i].lifeExpInWeeks * 7 == 0) {
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

		}
	}

	return objectsInSimulation;
}

std::vector<Object> removeObjectByLifeExpInWeeks(std::vector<Object> objectsInSimulation, unsigned short int days) {

	srand(time(NULL));

	bool whoWillDead = rand() % 1 + 1;

	for (int i = 0; i < objectsInSimulation.size(); i++) {
		if (days % objectsInSimulation[i].lifeExpInWeeks * 7 == 0) {
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

		}
	}

	return objectsInSimulation;
}

void simulation() {
	std::vector<Object> objects = infoObjects();
	std::vector<Object> objectsInSimulation;
	std::vector<bool> active;

	for (int i = 0; objects.size() - i > 0; i++) {
		active.push_back(false);
	}

	unsigned short int choice;
	unsigned short int days = 1, daysTimer = days;
	std::string mouth = "January";
	std::string season;

	while (true) {

		if (days == 365)
			days = 1;

		displayObjects(objectsInSimulation, objects, active, daysTimer, mouth, season);

		days += daysTimer;
		timer(daysTimer, mouth, false, choice);
		season = getSeason(daysTimer, mouth);

		/*
		if (active[--choice] != true)
			active[choice] = true;
		else
			break;

		if (objects[choice].food.empty()) {
			objects[choice].maleCount += 3;
			for (auto i = 0; i < 3; i++) {
				objectsInSimulation.push_back(objects[choice]);
			}
		}
		else {
			objects[choice].maleCount += 1;
			objects[choice].femaleCount += 1;
			for (auto i = 0; i < 2; i++) {
				objectsInSimulation.push_back(objects[choice]);
			}
		}
		*/

		/*
		for (int i = 0; i < objects.size(); i++) {
			if (days % objects[i].pregnancy == 0) {
				srand(time(NULL));
				int kids = rand() % 1 + 3;
				bool gender = rand() % 1;

			}
		}
		*/

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