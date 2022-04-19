#include "pch.h"
#include "logic-for-objects.h"

void simulation() {
	std::vector<Object> objects = infoObjects();

	unsigned short int days = 0;
	unsigned short int whatIsDoingInDaysOptions = 0;

	//while (true) {
		std::vector<std::string> objectsInSimulation = { "Mouse" , "Grass", "Grasshoper"};

		if (!objectsInSimulation.empty()) {
			++days;
		}
		
		for (auto i = 0; i != objectsInSimulation.size(); i++) { // i = 1 what.. = 0
			switch (whatIsDoingInDaysOptions) {
			case 0 :
				if (objectsInSimulation[i] == "Grass") {
					std::cout << "is there Grass\n";
					++whatIsDoingInDaysOptions;
					i = -1;
				}
				break;
			case 1:
				if (objectsInSimulation[i] == "Grasshoper") {
					std::cout << "is there Grasshoper\n";
					++whatIsDoingInDaysOptions;
					i = -1;
				}
				break;
			case 2:
				if (objectsInSimulation[i] == "Mouse") {
					std::cout << "is there Mouse\n";
					++whatIsDoingInDaysOptions;
					i = -1;
				}
				break;
			case 3:
				if (objectsInSimulation[i] == "Owl") {
					std::cout << "is there Owl\n";
					++whatIsDoingInDaysOptions;
					i = -1;
				}
				break;
			}
		}

		if (whatIsDoingInDaysOptions == 0) {
			std::cout << "all animals deaths\n";
		}
		else {
			std::cout << "whatIsDoingInDaysOptions: " << whatIsDoingInDaysOptions << std::endl;
		}

		std::cout << "Days: " << days;
	//}
}