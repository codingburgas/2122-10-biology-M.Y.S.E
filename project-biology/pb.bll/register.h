#pragma once

#include "pch.h"
#include "../pb.dal/register-files.h"

bool passwordHasNumbers(std::string);
bool passwordHasSymbols(std::string);
bool passwordIsGood(std::string);

void registerUser();