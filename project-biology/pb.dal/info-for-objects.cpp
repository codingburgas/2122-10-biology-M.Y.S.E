#include "pch.h"
#include "info-for-objects.h"

std::vector<Object> infoObjects() {

	std::vector<Object> objects

	/*Tuka vzimash tvoq fail ot papkite i vzimash dannite za jivotnite*/

	= {
		{"Grass", "Grass is a plant with narrow leaves growing from the base. A common kind of grass is used to cover the ground in a lawn and other places. Grass gets water from the roots in the ground.", "", 10, {}, NULL, NULL, NULL, NULL, 0.04, 0},
		{"Blueberry bushes", "They are an upright bush with a relatively shallow, fibrous root system and woody canes. Fruit is borne on buds formed during the previous growing season in late summer. Highbush blueberry plants leaf, flower, and fruit in June.", "", 40, {}, NULL, NULL, NULL, NULL, 0.5, 0},
		{"Flowers", "The primary purpose of the flower is reproduction. Since the flowers are the reproductive organs of the plant, they mediate the joining of the sperm, contained within pollen, to the ovules — contained in the ovary.", "", 12, {}, NULL, NULL, NULL, NULL, 0.4, 0},
		{"Grasshoppers", "grasshopper, any of a group of jumping insects that are found in a variety of habitats. Grasshoppers occur in greatest numbers in lowland tropical forests, semiarid regions, and grasslands.", "", 1, { "Grass" }, 35, -3, 2, 0, 3, 0},
		{"Mouses", "A mouse is a small rodent with a pointed nose, furry round body, large ears and a long, often hairless, tail. There are hundreds of types of mice, divided into subfamilies of either Old World or New World species.", "", 5, {"Grasshoppers"}, 5, 40, 2, 0, 0.75, 0},
		{"Owls", "Most owls have huge heads, stocky bodies, soft feathers, short tails, and a reversible toe that can point either forward or backward. Owl's eyes face forward, like humans do. Most owl species are active at night, not in the daytime.", "", 8, {"Mouses"}, 10, 40, 3, 0, 1, 0},
		{"Foxes", "Foxes are omnivorous mammals that are light on their feet. They are often mistaken for other members of the Canidae family, which include jackals, wolves and dogs. They stand out from their relatives because of their long, thin legs, lithe frame, pointed nose and bushy tail.", "", 4, {"Owls"}, 10, 60, 3, 0, 1.75, 0},
		{"Butterflies", "The scales, which are arranged in colorful designs unique to each species, are what gives the butterfly its beauty. Like all other insects, butterflies have six legs and three main body parts: head, thorax and abdomen.", "", 0.1, {"Blueberry bushes"}, 5, 60, 2, 0, 5, 0},
		{"Snakes", "There are more than 3,000 species of snakes on the planet and they're found everywhere except in Antarctica, Iceland, Ireland, Greenland, and New Zealand. About 600 species are venomous, and only about 200—seven percent—are able to kill or significantly wound a human.", "", 9, {"Mouses"}, 0, 55, 3, 0, 2, 0},
		{"Lizards", "Most lizards are active during the day. Lizards are cold-blooded animals, which means they rely on their environment to help warm their bodies. They use the heat of the sun to raise their body temperatures and are active when their bodies are warm.", "", 30, {"Bees"}, 5, 60, 3, 0, 10, 0},
		{"Bees", "Like all insects, a bee's body is divided into three parts: a head with two antennae, a thorax with six legs, and an abdomen. All bees have branched hairs somewhere on their bodies and two pairs of wings. Only female bees have stingers.", "", 0.1, { "Flowers" }, 10, 40, 3, 0, 0.75, 0},
		{"Bears", "Bears are mammals that belong to the family Ursidae. They can be as small as four feet long and about 60 pounds (the sun bear) to as big as eight feet long and more than a thousand pounds.", "", 20, { "Foxes" }, -10, 70, 3, 0, 9, 0}

	};

	/*objects.push_back(funckiq za kavalcho)*/
	
	/*kakvoGoQdeKavalcho*/

	/*Tuka se zapazvat novite promeni ot kavalcho v faila*/

	return objects;
}