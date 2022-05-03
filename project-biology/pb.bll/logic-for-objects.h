#pragma once

#include "pch.h"
#include "../pb.dal/info-for-objects.h"
#include "../pb.bll/simulation-date.h"

void simulation(bool&, bool&);
void time(unsigned short int& days, std::string& month, std::string& season, int& tempeture);
void removeObjectByLifeExpInYears(std::vector<Object>& objectsInSimulation, std::vector<Object> objects, std::vector<CountObjects>& counterInSimulation);
void removeObjectByTempeture(std::vector<Object>& objectsInSimulation, std::vector<Object> objects, std::vector<CountObjects>& counterInSimulation, int temp);
void removeObjectByFood(std::vector<Object>& objectsInSimulation, std::vector<Object> objects, std::vector<CountObjects>& counterInSimulation);
std::vector<std::string> objectFeelingByHunger(std::vector<Object>& objectsInSimulation, std::vector<Object> objects, std::vector<CountObjects>& counterInSimulation);
std::vector<std::string> objectFeelingObjectByTempeture(std::vector<Object> objects, int temp);
unsigned short int sumOfPopulation(std::vector<CountObjects> counterInSimulation, int key);
void startingAddObjectInSimulation(std::vector<Object>& objectsInSimulation, std::vector<Object> objects, std::vector<CountObjects>& counterInSimulation, size_t choice, unsigned short int days);
void pregnancyObjectInSimulation(std::vector<Object>& objectsInSimulation, std::vector<Object> objects, std::vector<CountObjects>& counterInSimulation);
std::vector<Object> logicSimulation(std::vector<Object> objectsInSimulation, std::vector<Object> objects, std::vector<CountObjects>& counterInSimulation, std::vector<unsigned short int> &active, size_t choice, unsigned short int days, int &temp);