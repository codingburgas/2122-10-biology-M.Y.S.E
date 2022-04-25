#pragma once

#include "pch.h"
#include "../pb.dal/info-for-objects.h"
#include "../pb.bll/simulation-date.h"

void simulation();
void displayObjects(std::vector<Object> objectsInSimulation, std::vector<Object> objects, std::vector<bool> active, unsigned short int days, std::string mouth, std::string season);
std::vector<Object> removeObjectByLifeExpInWeeks(std::vector<Object> objectsInSimulation, unsigned short int days);
std::vector<Object> removeObjectByHungerRateByDays(std::vector<Object> objectsInSimulation, unsigned short int days);