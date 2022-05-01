#pragma once

#include "pch.h"
#include "../pb.dal/info-for-objects.h"
#include "../pb.bll/simulation-date.h"

void simulation();
void time(unsigned short& days, unsigned short& daysTimer, std::string& mouth, size_t& choice, int& tempeture, std::string& season);
void displayObjects(std::vector<Object> objectsInSimulation, std::vector<Object> objects, std::vector<CountObjects>& counterInSimulation, std::vector<unsigned short int> active, unsigned short int days, std::string mouth, std::string season, int temp);
void removeObjectByLifeExpInYears(std::vector<Object>& objectsInSimulation, std::vector<Object> objects, std::vector<CountObjects>& counterInSimulation);
void removeObjectByTempeture(std::vector<Object>& objectsInSimulation, std::vector<Object> objects, std::vector<CountObjects>& counterInSimulation, int temp);
void removeObjectByFood(std::vector<Object>& objectsInSimulation, std::vector<Object> objects, std::vector<CountObjects>& counterInSimulation);
std::vector<std::string> objectFeelingByHunger(std::vector<Object>& objectsInSimulation, std::vector<Object> objects, std::vector<CountObjects>& counterInSimulation);
std::vector<std::string> objectFeelingObjectByTempeture(std::vector<Object> objects, int temp);
unsigned short int sumOfPopulation(std::vector<CountObjects> counterInSimulation, int key);
void startingAddObjectInSimulation(std::vector<Object>& objectsInSimulation, std::vector<Object> objects, std::vector<CountObjects>& counterInSimulation, size_t choice, unsigned short int days);
void pregnancyObjectInSimulation(std::vector<Object>& objectsInSimulation, std::vector<Object> objects, std::vector<CountObjects>& counterInSimulation);
std::vector<Object> logicSimulation(std::vector<Object> objectsInSimulation, std::vector<Object> objects, std::vector<CountObjects>& counterInSimulation, std::vector<unsigned short int> &active, size_t choice, unsigned short int days, int &temp);