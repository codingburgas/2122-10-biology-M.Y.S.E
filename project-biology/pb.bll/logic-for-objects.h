#pragma once

#include "pch.h"
#include "../pb.dal/info-for-objects.h"

void simulation();
void displayProducts(std::vector<Object> objectsInSimulation);
std::vector<Object> removeObject(std::vector<Object> objectsInSimulation, int i);
std::string displayGosho();