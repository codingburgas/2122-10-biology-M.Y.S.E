#include "pch.h"
#include "logic-for-objects.h"

void simulation() {
	std::vector<Object> objects = infoObjects();
	std::vector<std::string> objectsInSimulation;

	unsigned short int days = 0;
	unsigned short int choice;

	while (true) {

		std::cout << "Add 1.Grass 2.Grasshoper 3.Mouse - ";
		std::cin >> choice;

		++days;
		objectsInSimulation.push_back(objects[choice-1].name);
		
		for (auto i = 0; i != objectsInSimulation.size(); i++) 
		{
			for (auto m = 0; m != objectsInSimulation.size(); m++) {
				if (!(objectsInSimulation[i] == objects[m].name && objects[m].food.empty()))
				{
					for (int j = 0, n = 0; j != objectsInSimulation.size(); j++, n++)
					{
						if (objectsInSimulation[i] == objects[n].name && objects[n].food[j] == objectsInSimulation[j])
						{
							for (int k = 0; k != objectsInSimulation.size(); k++)
							{
								if (objectsInSimulation[k] == objectsInSimulation[j])
								{
									objectsInSimulation.erase(objectsInSimulation.begin() + k);
									break;
								}
							}
							objectsInSimulation.erase(objectsInSimulation.begin() + j);
							break;
						}
					}
				}
			}
		}

		std::cout << "Sega imash slednite obekti: ";
		for (auto i : objectsInSimulation)
			std::cout << i << ' ';
		std::cout << std::endl;

		std::cout << "Days: " << days << std::endl;
	}
}