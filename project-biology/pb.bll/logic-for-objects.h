#pragma once

#include "pch.h"
#include "../pb.dal/info-for-objects.h"
#include "../pb.bll/simulation-date.h"

void simulation();
void displayObjects(std::vector<Object> objectsInSimulation, std::vector<Object> objects, std::vector<CountObjects>& counterInSimulation, std::vector<bool> active, unsigned short int days, std::string mouth, std::string season, int temp);
std::vector<Object> removeObjectByLifeExpInWeeks(std::vector<Object> objectsInSimulation, unsigned short int days);
std::vector<Object> removeObjectByFood(std::vector<Object> objectsInSimulation, int i, unsigned short int days);
std::vector<Object> removeObjectByHungerRateByDays(std::vector<Object> objectsInSimulation, unsigned short int days);
std::vector<Object> startingAddObjectInSimulation(std::vector<Object> objectsInSimulation, std::vector<Object> objects, std::vector<CountObjects>& counterInSimulation, unsigned short int choice, unsigned short int days);
std::vector<Object> pregnancyObjectInSimulation(std::vector<Object> objectsInSimulation, std::vector<Object> objects, std::vector<CountObjects>& counterInSimulation);
std::vector<Object> logicSimulation(std::vector<Object> objectsInSimulation, std::vector<Object> objects, std::vector<CountObjects>& counterInSimulation, std::vector<bool> active, unsigned short int choice, unsigned short int days);