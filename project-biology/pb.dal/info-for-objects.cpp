#include "pch.h"
#include "info-for-objects.h"

// Gives a special values to the objects
std::vector<Object> infoObjects() {

	std::vector<Object> objects

	= {
		{"Grass", "Grass is a plant with narrow leaves growing from the base. A common kind of grass is used to cover the ground in a lawn and other places. Grass gets water from the roots in the ground.", "", 0.6, 0, {}, NULL, NULL, NULL, NULL, 0.04, 0},
		{"Blueberry bushes", "They are an upright bush with a relatively shallow, fibrous root system and woody canes. Fruit is borne on buds formed during the previous growing season in late summer. Highbush blueberry plants leaf, flower, and fruit in June.", "", 40, 0, {}, NULL, NULL, NULL, NULL, 0.5, 0},
		{"Flowers", "The primary purpose of the flower is reproduction. Since the flowers are the reproductive organs of the plant, they mediate the joining of the sperm, contained within pollen, to the ovules — contained in the ovary.", "", 12, 0, {}, NULL, NULL, NULL, NULL, 0.4, 0},
		{"Grasshoppers", "grasshopper, any of a group of jumping insects that are found in a variety of habitats. Grasshoppers occur in greatest numbers in lowland tropical forests, semiarid regions, and grasslands.", "", 1, 0, { "Grass" }, 25, -6, 2, 0, 0.5, 0},
		{"Butterflies", "The scales, which are arranged in colorful designs unique to each species, are what gives the butterfly its beauty. Like all other insects, butterflies have six legs and three main body parts: head, thorax and abdomen.", "", 0.1, 0, {"Blueberry bushes"}, 33, -5, 2, 0, 0.55, 0},
		{"Rabbits", "Rabbits are small mammals with fluffy, short tails, whiskers and distinctive long ears. There 29 species around the world, according to Nature by PBS and, while they live in many different environments, they have many things in common.", "", 9, 0, { "Grass" }, 29, -6, 3, 0, 0.4, 0 },
		{"Bees", "Like all insects, a bee's body is divided into three parts: a head with two antennae, a thorax with six legs, and an abdomen. All bees have branched hairs somewhere on their bodies and two pairs of wings. Only female bees have stingers.", "", 0.1, 0, { "Flowers" }, 28, -5, 3, 0, 0.65, 0},
		{"Mouses", "A mouse is a small rodent with a pointed nose, furry round body, large ears and a long, often hairless, tail. There are hundreds of types of mice, divided into subfamilies of either Old World or New World species.", "", 5, 0, {"Grasshoppers"}, 32, -6, 2, 0, 0.5, 0},
		{"Lizards", "Most lizards are active during the day. Lizards are cold-blooded animals, which means they rely on their environment to help warm their bodies. They use the heat of the sun to raise their body temperatures and are active when their bodies are warm.", "", 30, 0, {"Bees"}, 27, -6, 3, 0, 0.6, 0},
		{"Owls", "Most owls have huge heads, stocky bodies, soft feathers, short tails, and a reversible toe that can point either forward or backward. Owl's eyes face forward, like humans do. Most owl species are active at night, not in the daytime.", "", 8, 0, {"Mouses"}, 29, -6, 3, 0, 0.67, 0},
		{"Foxes", "Foxes are omnivorous mammals that are light on their feet. They are often mistaken for other members of the Canidae family, which include jackals, wolves and dogs. They stand out from their relatives because of their long, thin legs, lithe frame, pointed nose and bushy tail.", "", 4, 0, {"Owls"}, 33, -5, 3, 0, 0.65, 0},
		{"Snakes", "There are more than 3,000 species of snakes on the planet and they're found everywhere except in Antarctica, Iceland, Ireland, Greenland, and New Zealand. About 600 species are venomous, and only about 200—seven percent—are able to kill or significantly wound a human.", "", 9, 0, {"Mouses"}, 32, -5, 3, 0, 0.4, 0},
		{"Bears", "Bears are mammals that belong to the family Ursidae. They can be as small as four feet long and about 60 pounds (the sun bear) to as big as eight feet long and more than a thousand pounds.", "", 20, 0, { "Foxes" }, 70, -10, 3, 0, 0.9, 0}
	};

	return objects;
}