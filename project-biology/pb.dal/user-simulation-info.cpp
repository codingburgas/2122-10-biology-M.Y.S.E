#include "pch.h"
#include "user-simulation-info.h"

// Saves simulations to file
void saveSimulationToFile(std::vector<Object> objectsInSimulation, std::vector<CountObjects> counterInSimulation, std::vector<Object> objectsOrder)
{
	std::ofstream simulationFile("../pb.dal/files/simulationInfo.txt");

	for (size_t i = 0; i < objectsInSimulation.size(); i++)
	{
		simulationFile << objectsInSimulation[i].name << "|";
		simulationFile << objectsInSimulation[i].information << "|";
		simulationFile << objectsInSimulation[i].gender << "|";
		simulationFile << objectsInSimulation[i].lifeExpInYears << "|";
		simulationFile << objectsInSimulation[i].remainingDaysToDead << "|";
		if (!(objectsInSimulation[i].food.empty()))
		{
			simulationFile << objectsInSimulation[i].food[0] << "|";
		}
		simulationFile << objectsInSimulation[i].maxTemp << "|";
		simulationFile << objectsInSimulation[i].minTemp << "|";
		simulationFile << objectsInSimulation[i].hunger << "|";
		simulationFile << objectsInSimulation[i].hungerRateByDays << "|";
		simulationFile << objectsInSimulation[i].pregnancy << "|";
		simulationFile << objectsInSimulation[i].remainingDaysToGiveBirth << "\n";
	}
	simulationFile.close();

	std::ofstream counterFile("../pb.dal/files/counter.txt");

	for (size_t i = 0; i < counterInSimulation.size(); i++)
	{
		counterFile << counterInSimulation[i].maleCount << "|";
		counterFile << counterInSimulation[i].femaleCount << "|";
		counterFile << counterInSimulation[i].deadCount << "\n";
	}

	counterFile.close();
}

// Get info from files and transfer it to variable
void addSimulationDataToVariables(std::vector<Object>& objectsInSimulation, std::vector<CountObjects>& counterInSimulation, std::vector<Object> objectsOrder) 
{
	std::ifstream file("../pb.dal/files/simulationInfo.txt");
	std::string line, enter;
	int i = 0;

	while(getline(file, enter, '\n'))
	{
		std::ofstream helperr("../pb.dal/files/helper.txt");
		helperr << enter << "";
		helperr.close();
		std::ifstream helper("../pb.dal/files/helper.txt", std::ios::in);
		getline(helper, line, '|');
		for (int j = 0; j < objectsOrder.size(); j++) {
			if (objectsOrder[j].name == line) {
				objectsInSimulation.push_back(objectsOrder[j]);
				break;
			}
		}
		getline(helper, line, '|');
		objectsInSimulation[i].information = line;
		getline(helper, line, '|');
		objectsInSimulation[i].gender = line;
		getline(helper, line, '|');
		objectsInSimulation[i].lifeExpInYears = stof(line);
		getline(helper, line, '|');
		objectsInSimulation[i].remainingDaysToDead = stof(line);
		if (!(objectsInSimulation[i].food.empty()))
		{
			getline(helper, line, '|');
			objectsInSimulation[i].food.push_back(line);
		}
		getline(helper, line, '|');
		objectsInSimulation[i].maxTemp = stoi(line);
		getline(helper, line, '|');
		objectsInSimulation[i].minTemp = stoi(line);
		getline(helper, line, '|');
		objectsInSimulation[i].hunger = stoi(line);
		getline(helper, line, '|');
		objectsInSimulation[i].hungerRateByDays = stoi(line);
		getline(helper, line, '|');
		objectsInSimulation[i].pregnancy = stof(line);
		getline(helper, line, '\n');
		objectsInSimulation[i].remainingDaysToGiveBirth = stof(line);

		i++;
		helper.close();
		helperr.close();
	}

	file.close();

	std::ifstream counterFile("../pb.dal/files/counter.txt");

	for (size_t i = 0; i < counterInSimulation.size(); i++)
	{
		getline(counterFile, line, '|');
		counterInSimulation[i].maleCount = stoi(line);
		getline(counterFile, line, '|');
		counterInSimulation[i].femaleCount = stoi(line);
		getline(counterFile, line, '\n');
		counterInSimulation[i].deadCount = stoi(line);
	}

	counterFile.close();
}