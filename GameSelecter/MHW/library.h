#pragma once
#include "constants.h"

//C
void setSeed() {
	srand((unsigned)time(NULL));
}

//R
int* readWeightsFromFile(char* personName) {
	//copy filename
	char fileName[LENGTH] = { 0 };
	strncpy(fileName, personName, LENGTH);

	//concatinate .txt to name
	strncat(fileName, ".txt", 5);

	int* weaponWeights = malloc(sizeof(int) * WEAPONTYPES);
	if (weaponWeights == NULL) {
		perror(EXITMESSAGE);
		exit(EXIT_FAILURE);
	}

	//create and check file, default if failed to open
	FILE* fp = fopen(fileName, "r");
	if (fp == NULL) {
		perror("Could not open file, defulting values...\n");
		for (int i = 0; i < WEAPONTYPES; i++)
			weaponWeights[i] = MAXWEAPONWEIGHT;
	}
	//otherwise read file, if value cannot be read then default it
	else {
		for (int i = 0; i < WEAPONTYPES; i++) {
			int tmp;
			if (fscanf(fp, "%d", &tmp) == 1 && MINWEAPONWEIGHT <= tmp && tmp <= MAXWEAPONWEIGHT)
				weaponWeights[i] = tmp;
			else
				weaponWeights[i] = MAXWEAPONWEIGHT;
		}
		fclose(fp);
	}

	return weaponWeights;
}

int determineWeapon(int* weaponWeights) {
	//add up total weapon weights
	int total = 0;
	for (int i = 0; i < WEAPONTYPES; i++)
		total += weaponWeights[i];

	//malloc new weapon weight system
	int* weaponWeightSystem = (int*)malloc(sizeof(int) * total);
	if (weaponWeightSystem == NULL) {
		perror("Couln't malloc space for weight system...\n");
		return INVALID;	//default value for system to return 
	}

	//loop through weapon types
	//loop through each weapon weight index to determine how much weighting to add to system
	//increase index every time number is added to system
	int index = 0;
	for (int i = 0; i < WEAPONTYPES; i++)
		for (int j = 0; j < weaponWeights[i]; j++)
			weaponWeightSystem[index++] = i + 1;

	//get return value and free weight system
	int toReturn = (weaponWeightSystem[rand() % total]);
	free(weaponWeightSystem);
	return toReturn;
}

char* getWeapon(int weaponNum) {
	char* weaponType = "";

	//switch for weapon types
	switch (weaponNum) {
	case 1:
		weaponType = "Great Sword";
		break;
	case 2:
		weaponType = "Long Sword";
		break;
	case 3:
		weaponType = "Sword & Shield";
		break;
	case 4:
		weaponType = "Dual Blades";
		break;
	case 5:
		weaponType = "Bonkmageddon";
		break;
	case 6:
		weaponType = "Hunting Horn";
		break;
	case 7:
		weaponType = "Lance";
		break;
	case 8:
		weaponType = "Gunlance";
		break;
	case 9:
		weaponType = "Switch Axe";
		break;
	case 10:
		weaponType = "Charge Blade";
		break;
	case 11:
		weaponType = "Insect Glaive";
		break;
	case 12:
		weaponType = "Light Bow Gun";
		break;
	case 13:
		weaponType = "Heavy Bow Gun";
		break;
	case 14:
		weaponType = "Bow";
		break;
	default:
		weaponType = "I have failed you D:";
		break;
	}

	return weaponType;
}

//U
void increaseWeaponWeights(int* weaponWeights, int weaponNumber) {
	for (int i = 0; i < WEAPONTYPES; i++) {
		//if the selected weapon is in the loop, set its value to the lowest weight value so it can't be selected again
		if (i + EXTRAINDEX == weaponNumber)
			weaponWeights[i] = MINWEAPONWEIGHT;
		else {
			//otherwise increase the value of the current index, and check its below the max weight value
			weaponWeights[i]++;
			if (weaponWeights[i] > MAXWEAPONWEIGHT)
				weaponWeights[i] = MAXWEAPONWEIGHT;
		}
	}
}

void writeWeightsToFile(char* personName, int* weaponWeights) {
	//copy filename
	char fileName[LENGTH] = { 0 };
	strncpy(fileName, personName, LENGTH);

	//concatinate .txt to name
	strncat(fileName, ".txt", 5);

	//create and check file, default if failed to open
	FILE* fp = fopen(fileName, "w");
	if (fp == NULL) {
		perror("Could not open file...\n");
		return;
	}
	//otherwise read file, if value cannot be read then default it
	else {
		for (int i = 0; i < WEAPONTYPES; i++) {
			fprintf(fp, "%d\n", weaponWeights[i]);
		}
		fclose(fp);
	}
}

//D