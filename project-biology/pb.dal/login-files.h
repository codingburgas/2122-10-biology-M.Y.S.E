#pragma once

#include "pch.h"

std::string getCurrentUser();
void addCurrentUser(std::string);
int getId(std::string, std::string);
bool userExists(std::string, std::string);