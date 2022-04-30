#pragma once

#include "pch.h"
#include "../pb.types/bio-object.h"

bool accIsSaved(std::string);
void saveSimulationToFile(std::string, std::vector<Object>, std::vector<CountObjects>);