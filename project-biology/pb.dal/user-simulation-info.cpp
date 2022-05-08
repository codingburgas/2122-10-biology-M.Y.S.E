#include "pch.h"
#include "user-simulation-info.h"

bool accIsSaved()
{
	std::ifstream simulationFile("../pb.dal/files/simulationInfo.txt");
	std::string line;
	std::string user = getCurrentUser();

	while (getline(simulationFile, line))
	{
		if (line.find(user) != std::string::npos)
		{
			return true;
		}
	}
	return false;
}

void saveSimulationToFile(std::vector<Object> objectsInSimulation, std::vector<CountObjects> counterInSimulation, std::vector<Object> objectsOrder)
{
	std::ifstream currentUserFile("currentUser.txt");
	if (!currentUserFile.good())
	{
		currentUserFile.close();
		return;
	}
	currentUserFile.close();

	std::ofstream simulationFile("../pb.dal/files/simulationInfo.txt", std::ios::trunc);

	for (size_t i = 0; i < objectsInSimulation.size(); i++)
	{
		simulationFile << objectsInSimulation[i].name << "|";
		simulationFile << objectsInSimulation[i].information << "|";
		simulationFile << objectsInSimulation[i].gender << "|";
		simulationFile << objectsInSimulation[i].lifeExpInYears << "|";
		simulationFile << objectsInSimulation[i].remainingDaysToDead << "|";

		for (size_t j = 0; j < objectsInSimulation[i].food.size(); j++)
		{
			simulationFile << objectsInSimulation[i].food[j] << "_";
		}

		simulationFile << objectsInSimulation[i].maxTemp << "|";
		simulationFile << objectsInSimulation[i].minTemp << "|";
		simulationFile << objectsInSimulation[i].hunger << "|";
		simulationFile << objectsInSimulation[i].hungerRateByDays << "|";
		simulationFile << objectsInSimulation[i].pregnancy << "|";
		simulationFile << objectsInSimulation[i].remainingDaysToGiveBirth << "|";

		for (size_t j = 0; j < objectsOrder.size(); j++)
		{
			if (objectsInSimulation[i].name == objectsOrder[j].name)
			{
				simulationFile << counterInSimulation[j].maleCount << "|";
				simulationFile << counterInSimulation[j].femaleCount << "|";
				simulationFile << counterInSimulation[j].deadCount << "\n";
				break;
			}
		}
	}
	simulationFile.close();
}

void addSimulationDataToVariables(std::vector<Object>& objectsInSimulation, std::vector<CountObjects>& counterInSimulation, std::vector<Object> objectsOrder) 
{
	std::ifstream file("../pb.dal/files/simulationInfo.txt");
	std::string line;
	int i = 0;

	while(!file.eof())
	{
		getline(file, line, '|');
		objectsInSimulation[i].name = line;
		getline(file, line, '|');
		objectsInSimulation[i].information = line;
		getline(file, line, '|');
		objectsInSimulation[i].gender = line;
		getline(file, line, '|');
		objectsInSimulation[i].lifeExpInYears = stof(line);
		getline(file, line, '|');
		objectsInSimulation[i].remainingDaysToDead = stof(line);

		getline(file, line, '_');
		objectsInSimulation[i].food.push_back(line);

		getline(file, line, '|');
		objectsInSimulation[i].maxTemp = stoi(line);
		getline(file, line, '|');
		objectsInSimulation[i].minTemp = stoi(line);
		getline(file, line, '|');
		objectsInSimulation[i].hunger = stoi(line);
		getline(file, line, '|');
		objectsInSimulation[i].hungerRateByDays = stoi(line);
		getline(file, line, '|');
		objectsInSimulation[i].pregnancy = stof(line);
		getline(file, line, '|');
		objectsInSimulation[i].remainingDaysToGiveBirth = stof(line);

		for (size_t j = 0; j < objectsOrder.size(); j++)
		{
			if (objectsInSimulation[i].name == objectsOrder[j].name)
			{
				getline(file, line, '|');
				counterInSimulation[j].maleCount = stoi(line);
				getline(file, line, '|');
				counterInSimulation[j].femaleCount = stoi(line);
				getline(file, line, '|');
				counterInSimulation[j].deadCount = stoi(line);
				break;
			}
		}
		i++;
	}

	file.close();
}