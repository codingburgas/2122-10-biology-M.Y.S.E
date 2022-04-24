#include "pch.h"
#include "info-for-objects.h"

std::vector<Object> infoObjects() {
	std::vector<Object> objects = {
		{"Grass", "to e treva", 8, {}, NULL, NULL, NULL, NULL, 3, NULL, NULL},
		{"Grasshoper", "to e skakalec", 12, {"Grass"}, 35, -3, 0, 0.4, 0, 0, 0},
		{"Mouse", "to e mishka", 24, {"Grasshoper"}, 40, -7, 0, 0.7, 0, 0, 0},
		{"Owl", "to e sova", 96, {"Mouse"}, 37, -9, 0, 0.3, 0, 0, 0}
	};

	return objects;
}