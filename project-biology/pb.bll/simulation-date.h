#pragma once

#include "pch.h"

void switchDate(unsigned short int&, std::string&);

void timer(unsigned short int& day, std::string& month, bool isPaused, unsigned short int& choice);

int getIndex(std::vector<std::string>, std::string);

std::string getSeason(unsigned short int, std::string);

int getTemperature(std::string);