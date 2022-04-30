#include "pch.h"
#include "user-simulation-info.h"

bool accIsSaved()
{
	std::ifstream simulationFile("simulationInfo.txt");
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

void saveSimulationToFile(std::vector<Object> objectsInSimulation, std::vector<CountObjects> counterInSimulation)
{
	std::string username = getCurrentUser();
	std::ofstream simulationFile;

	if (!accIsSaved)
	{
		simulationFile.open("simulationInfo.txt", std::ios::app);
		
		simulationFile << "User:" + username << "\n";

		for (size_t i = 0; i < objectsInSimulation.size(); i++)
		{

		}
	}

	if (!simulationFile.is_open())
	{
		simulationFile.open("simulationInfo.txt");
	}
}