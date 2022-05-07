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
	std::ofstream simulationFile("../pb.dal/files/simulationInfo.txt");

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