#pragma once

#include "pch.h"
#include "../pb.types/bio-object.h"
#include "../pb.dal/login-files.h"

bool accIsSaved();
void saveSimulationToFile(std::vector<Object>, std::vector<CountObjects>, std::vector<Object>);