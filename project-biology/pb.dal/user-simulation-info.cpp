#include "pch.h"
#include "user-simulation-info.h"

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
		getline(helper, line, '|');
		objectsInSimulation[i].gender = line;
		getline(helper, line, '|');
		getline(helper, line, '|');
		objectsInSimulation[i].remainingDaysToDead = stof(line);
		getline(helper, line, '_');
		getline(helper, line, '|');
		getline(helper, line, '|');
		getline(helper, line, '|');
		getline(helper, line, '|');
		objectsInSimulation[i].hungerRateByDays = stoi(line);
		getline(helper, line, '|');
		getline(helper, line, '|');
		objectsInSimulation[i].remainingDaysToGiveBirth = stof(line);

		for (size_t j = 0; j < objectsOrder.size(); j++)
		{
			if (objectsInSimulation[i].name == objectsOrder[j].name)
			{
				getline(helper, line, '|');
				counterInSimulation[j].maleCount = stoi(line);
				getline(helper, line, '|');
				counterInSimulation[j].femaleCount = stoi(line);
				getline(helper, line, '|');
				counterInSimulation[j].deadCount = stoi(line);
				break;
			}
		}
		i++;
		helper.close();
		helperr.close();
	}

	file.close();
}