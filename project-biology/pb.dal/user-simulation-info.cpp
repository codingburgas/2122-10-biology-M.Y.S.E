#include "pch.h"
#include "user-simulation-info.h"

bool accIsSaved()
{
	std::ifstream simulationFile("../pb.dal/file/simulationInfo.txt");
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
	std::fstream simulationFile;

	if (!accIsSaved())
	{
		simulationFile.open("../pb.dal/file/simulationInfo.txt", std::ios::app);
		
		simulationFile << "User:" + username << "\n";

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
		}

		for (size_t i = 0; i < counterInSimulation.size(); i++)
		{
			simulationFile << counterInSimulation[i].maleCount << "|";
			simulationFile << counterInSimulation[i].femaleCount << "|";
			simulationFile << counterInSimulation[i].deadCount << "\n";
		}

		simulationFile << "End\n";
		simulationFile.close();
		return;
	}

	if (!simulationFile.is_open())
	{
		simulationFile.open("../pb.dal/file/simulationInfo.txt");
	}

	simulationFile.open("../pb.dal/file/simulationInfo.txt");
	std::string line;

	std::fstream tempFile("../pb.dal/file/temp.txt", std::ios::trunc);
	while (line != username)
	{
		getline(simulationFile, line);
		tempFile << line << "\n";
	}

	for (size_t i = 0; i < objectsInSimulation.size(); i++)
	{
		tempFile << objectsInSimulation[i].name << "|";
		tempFile << objectsInSimulation[i].information << "|";
		tempFile << objectsInSimulation[i].gender << "|";
		tempFile << objectsInSimulation[i].lifeExpInYears << "|";
		tempFile << objectsInSimulation[i].remainingDaysToDead << "|";

		for (size_t j = 0; j < objectsInSimulation[i].food.size(); j++)
		{
			tempFile << objectsInSimulation[i].food[j] << "_";
		}

		tempFile << objectsInSimulation[i].maxTemp << "|";
		tempFile << objectsInSimulation[i].minTemp << "|";
		tempFile << objectsInSimulation[i].hunger << "|";
		tempFile << objectsInSimulation[i].hungerRateByDays << "|";
		tempFile << objectsInSimulation[i].pregnancy << "|";
		tempFile << objectsInSimulation[i].remainingDaysToGiveBirth << "|";
	}

	for (size_t i = 0; i < counterInSimulation.size(); i++)
	{
		tempFile << counterInSimulation[i].maleCount << "|";
		tempFile << counterInSimulation[i].femaleCount << "|";
		tempFile << counterInSimulation[i].deadCount << "\n";
	}

	tempFile << "End\n";

	while (line != "End")
	{
		getline(simulationFile, line);
	}

	while (getline(simulationFile, line))
	{
		tempFile << line << "\n";
	}

	tempFile.clear();
	tempFile.seekg(0, std::ios::beg);
	simulationFile.clear();
	simulationFile.seekg(0, std::ios::beg);

	simulationFile.close();
	simulationFile.open("../pb.dal/file/simulationInfo.txt", std::ios::trunc);

	while (getline(tempFile, line))
	{
		simulationFile << line << "\n";
	}

	simulationFile.close();
	tempFile.close();
}