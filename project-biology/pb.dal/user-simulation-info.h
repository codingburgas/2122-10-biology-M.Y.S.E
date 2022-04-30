#pragma once

#include "pch.h"
#include "../pb.types/bio-object.h"

std::string getCurrentUser();
void addCurrentUser(std::string);
bool accIsSaved(std::string);
void saveSimulationToFile(std::string, std::vector<Object>, std::vector<CountObjects>);