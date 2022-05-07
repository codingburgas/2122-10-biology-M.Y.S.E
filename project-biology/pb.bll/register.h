#pragma once

#include "pch.h"
#include "../pb.dal/login-files.h"
#include "../pb.dal/register-files.h"
#include "../pb.types/sha256.h"

bool passwordHasNumbers(std::string);
bool passwordHasSymbols(std::string);
int passwordIsGood(std::string, std::string);

int registerUser(std::string, std::string, std::string);