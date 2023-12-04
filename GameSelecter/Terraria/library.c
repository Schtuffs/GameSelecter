#include <stdio.h>
#include <time.h>
#include <string.h>
#include "library.h"
#define LENGTH			20
#define CLASSTYPES		5
#define SUBCLASSTYPES	3

int GetInput()
{
	int Select;
	printf("Enter a number:\n");
	printf("1) Basic Class\n");
	printf("2) Subclass\n");
	scanf_s("%d", &Select);
	return Select;
}

char* GetClass()
{
	//set seed for random number generation (from time)
	srand(time(NULL));
	char* ClassType = "";

	//get random number based on seed
	int ClassNum = (rand() % CLASSTYPES + 1);

	//switch for weapon types

	switch (ClassNum)
	{
	case 1:
		ClassType = "Melee";
		break;
	case 2:
		ClassType = "Ranged";
		break;
	case 3:
		ClassType = "Mage";
		break;
	case 4:
		ClassType = "Summoner";
		break;
	case 5:
		ClassType = "Rogue";
		break;
	default:
		ClassType = "I have failed you D:";
	}

	return ClassType;
}

char* GetSubClass(char *Class)
{
	srand(time(NULL));
	char* SubClassType = "";

	//switch for weapon types
	if (strncmp("Melee", Class, LENGTH) == 0)
	{
		int SubClassNum = (rand() % 7 + 1);
		switch (SubClassNum)
		{
		case 1:
			SubClassType = "All Melee";
			break;
		case 2:
			SubClassType = "True Melee";
			break;
		case 3:
			SubClassType = "(Short/)Swords Only";
			break;
		case 4:
			SubClassType = "Spears Only";
			break;
		case 5:
			SubClassType = "Boomerangs Only";
			break;
		case 6:
			SubClassType = "Flails Only";
			break;
		case 7:
			SubClassType = "Special Melee";
			break;
		default:
			SubClassType = "Mission Failed";
		}
	}
	else if (strncmp("Ranged", Class, LENGTH) == 0)
	{
		int SubClassNum = (rand() % 5 + 1);
		switch (SubClassNum)
		{
		case 1:
			SubClassType = "All Ranged";
			break;
		case 2:
			SubClassType = "Bows/Repeaters Only";
			break;
		case 3:
			SubClassType = "Guns Only";
			break;
		case 4:
			SubClassType = "Rockets Only";
			break;
		case 5:
			SubClassType = "Special Ranged";
			break;
		default:
			SubClassType = "Mission Failed";
		}
	}
	else if (strncmp("Mage", Class, LENGTH) == 0)
	{
		int SubClassNum = (rand() % 5 + 1);
		switch (SubClassNum)
		{
		case 1:
			SubClassType = "All Magic";
			break;
		case 2:
			SubClassType = "Staves Only";
			break;
		case 3:
			SubClassType = "Books Only";
			break;
		case 4:
			SubClassType = "Magic Guns Only";
			break;
		case 5:
			SubClassType = "Special Mage";
			break;
		default:
			SubClassType = "Mission Failed";
		}
	}
	else if (strncmp("Summoner", Class, LENGTH) == 0)
	{
		int SubClassNum = (rand() % 3 + 1);
		switch (SubClassNum)
		{
		case 1:
			SubClassType = "All Summons";
			break;
		case 2:
			SubClassType = "Summons & Whips";
			break;
		case 3:
			SubClassType = "Sentries & Whips";
			break;
		default:
			SubClassType = "Mission Failed";
		}
	}
	else if (strncmp("Rogue", Class, LENGTH) == 0)
	{
		int SubClassNum = (rand() % 7 + 1);
		switch (SubClassNum)
		{
		case 1:
			SubClassType = "All Rogue";
			break;
		case 2:
			SubClassType = "Bombs Only";
			break;
		case 3:
			SubClassType = "Boomerangs Only";
			break;
		case 4:
			SubClassType = "Daggers Only";
			break;
		case 5:
			SubClassType = "Javelins Only";
			break;
		case 6:
			SubClassType = "Spikey Balls Only";
			break;
		case 7:
			SubClassType = "Special Rogue";
			break;
		default:
			SubClassType = "Mission Failed";
		}
	}
	return SubClassType;
}

void PrintClassType(char* ClassType, char* SubClassType)
{
	printf("Your class is: %s", ClassType);
	if (strcmp(SubClassType, "") != 0)
		printf(", and your subclass is: %s", SubClassType);
	printf("\n");
}