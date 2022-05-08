#pragma once

#include "pch.h"
#include "../pb.dal/info-for-objects.h"
#include "../pb.dal/user-simulation-info.h"
#include "../pb.bll/simulation-date.h"

void choiceSystem(std::string& textTime, short& choice);

void timeSystem(std::fstream& timeFile, std::string& textTime, int& i, unsigned short& days, std::string& month, std::string& season, int& temp);

void simulation(bool&, bool&);
void time(unsigned short int& days, std::string& month, std::string& season, int& tempeture);
void removeObjectByLifeExpInYears(std::vector<Object>& objectsInSimulation, std::vector<Object> objects, std::vector<CountObjects>& counterInSimulation);
void removeObjectByTempeture(std::vector<Object>& objectsInSimulation, std::vector<Object> objects, std::vector<CountObjects>& counterInSimulation, int temp);
void removeObjectByFood(std::vector<Object>& objectsInSimulation, std::vector<Object> objects, std::vector<CountObjects>& counterInSimulation);
std::vector<std::string> objectFeelingByHunger(std::vector<Object>& objectsInSimulation, std::vector<Object> objects, std::vector<CountObjects>& counterInSimulation);
std::vector<std::string> objectFeelingObjectByTempeture(std::vector<Object> objects, int temp);
unsigned short int sumOfPopulation(std::vector<CountObjects> counterInSimulation, int key);
void startingAddObjectInSimulation(std::vector<Object>& objectsInSimulation, std::vector<Object> objects, std::vector<CountObjects>& counterInSimulation, short int choice);
void pregnancyObjectInSimulation(std::vector<Object>& objectsInSimulation, std::vector<Object> objects, std::vector<CountObjects>& counterInSimulation);
std::vector<Object> logicSimulation(std::vector<Object> objectsInSimulation, std::vector<Object> objects, std::vector<CountObjects>& counterInSimulation, short int choice, int &temp, bool start);