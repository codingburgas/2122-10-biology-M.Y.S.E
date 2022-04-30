#include "pch.h"
#include "user-simulation-info.h"

bool accIsSaved(std::string username)
{
	std::ifstream simulationFile("simulationInfo.txt");
	std::string line;
	std::string user = username;

	while (getline(simulationFile, line))
	{
		if (line.find(user) != std::string::npos)
		{
			return true;
		}
	}
	return false;
}

void saveSimulationToFile(std::string username, std::vector<Object> objectsInSimulation, std::vector<CountObjects> counterInSimulation)
{
	std::ofstream simulationFile("simulationInfo.txt");

	if (!accIsSaved)
	{
		while (!simulationFile.eof())
		{
			getline(simulationFile, line)
		}
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