#include "pch.h"
#include "info-for-objects.h"

std::vector<Object> infoObjects() {

	std::vector<Object> objects

	/*Tuka vzimash tvoq fail ot papkite i vzimash dannite za jivotnite*/

	= {
		{"Grass", "to e treva", 8, {}, NULL, NULL, NULL, NULL, 0, NULL, NULL},
		{"Grasshopers", "to e skakalec", 12, {"Grass"}, 35, -3, 0, 0.4, 0, 0, 3},
		{"Mouses", "to e mishka", 24, {"Grasshopers"}, 40, -7, 0, 0.7, 0, 0, 3},
		{"Owls", "to e sova", 96, {"Mouses"}, 37, -9, 0, 0.3, 0, 0, 4}

	};

	/*objects.push_back(funckiq za kavalcho)*/
	
	/*kakvoGoQdeKavalcho*/

	/*Tuka se zapazvat novite promeni ot kavalcho v faila*/

	return objects;
}