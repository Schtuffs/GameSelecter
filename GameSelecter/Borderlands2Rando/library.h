#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "constants.h"

//restriction types
 
const char* characters[] = { "Axton", "Gaige", "Krieg", "Maya", "Salvador", "Zer0" };
const int totalCharacters = sizeof(characters) / sizeof(*characters);

const char* weaponRestrictions[] = { "Assault Rifles only", "Pistols only", "Rocket Launchers only", "Shotguns only", "SMGs only", "Snipers only" };
const int totalWeaponRestrictions = sizeof(weaponRestrictions) / sizeof(*weaponRestrictions);

const char* manufacturerRestrictions[] = { "Bandit only", "Dahl only", "Hyperion only", "Jacobs only", "Maliwan only", "Tediore only", "TORGUE only", "Vladof only" };
const int totalManufacturerRestrictions = sizeof(manufacturerRestrictions) / sizeof(*manufacturerRestrictions);

int compare(const int* v1, const int* v2) {
	if (*v1 > *v2)
		return 1;
	if (*v1 == *v2)
		return 0;
	return -1;
}

void addCharacterRestriction() {
	int selection = rand() % totalCharacters;
	printf("Character available: %s\n", characters[selection]);
}

void addWeaponRestriction() {
	int selection = rand() % totalWeaponRestrictions;
	printf("Weapon type available: %s\n", weaponRestrictions[selection]);
}

void addManuRestriction() {
	int selection = rand() % totalManufacturerRestrictions;
	printf("Manufacturer available: %s\n", manufacturerRestrictions[selection]);
}

void playthroughHell(int* restrictions, int totalRestrictions) {
	//newlines for some cleanliness
	for(int i = 0; i < 10; i++)
		printf("\n");

	//sort array for nicer output
	qsort(restrictions, totalRestrictions, sizeof(int), compare);

	//switch for adding restrictions
	for(int i = 0; i < totalRestrictions; i++) {
		switch (restrictions[i]) {
		case CHARACTERRESTRICT:
			addCharacterRestriction();
			break;
		case WEAPONRESTRICT:
			addWeaponRestriction();
			break;
		case MANURESTRICT:
			addManuRestriction();
			break;
		default:
			break;
		}
	}
}