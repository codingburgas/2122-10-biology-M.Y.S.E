#include "pch.h"
#include "logic-for-objects.h"

std::string displayGosho() {
	return "Gosho";
}

void displayProducts(std::vector<Object> objectsInSimulation)
{
	if (objectsInSimulation.empty())
		std::cout << "\nSorry, no values exist in the data.";
	else
		std::cout << "Area: ";
		for (int count = 0; count < objectsInSimulation.size(); count++)
		{
			std::cout << objectsInSimulation[count].name << " ";
		}
	std::cout << std::endl;
}

std::vector<Object> removeObject(std::vector<Object> objectsInSimulation, int i) {

	srand(time(NULL));

	int whoWillEat = rand() % 1 + 1;

	if (objectsInSimulation[i].maleCount == 0) {
		--objectsInSimulation[i].femaleCount;
	}
	else if (objectsInSimulation[i].femaleCount == 0) {
		--objectsInSimulation[i].maleCount;
	} else {
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

void simulation() {
	std::vector<Object> objects = infoObjects();
	std::vector<Object> objectsInSimulation;

	unsigned short int days = 0;
	unsigned short int choice;

	while (true) {

		++days;
		std::cout << "Days: " << days << std::endl;

		std::cout << "Add 1.Grass 2.Grasshoper 3.Mouse - ";
		std::cin >> choice;

		objectsInSimulation.push_back(objects[--choice]);

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


		displayProducts(objectsInSimulation);

	}
}