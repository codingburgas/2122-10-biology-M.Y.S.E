#include "pch.h"
#include "user-simulation-info.h"

bool accIsSaved(std::string firstName, std::string lastName)
{
	std::ifstream simulationFile("simulationInfo.txt");
	std::string line;
	std::string user = firstName + lastName;

	while (getline(simulationFile, line))
	{
		if (line.find(user) != std::string::npos)
		{
			return true;
		}
	}
	return false;
}

void saveSimulationToFile(std::string firstName, std::string lastName, std::vector<Object> objectsInSimulation)
{
	std::ofstream simulationFile;

	if (!accIsSaved)
	{
		simulationFile.open("simulationInfo.txt", std::ios::app);
		
		simulationFile << "User:" + firstName + lastName << "\n";

		for (size_t i = 0; i < objectsInSimulation.size(); i++)
		{

		}
	}

	if (!simulationFile.is_open())
	{
		simulationFile.open("simulationInfo.txt");
	}
}