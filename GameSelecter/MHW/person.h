#pragma once
#include "constants.h"

typedef struct people {
	struct node* head;
}PEOPLE;

typedef struct node {
	char name[LENGTH];
	struct node* next;
}NODE;

//C
PEOPLE* createPersonList() {
	PEOPLE* p = (PEOPLE*)malloc(sizeof(PEOPLE));
	if (p == NULL) {
		perror("Couldn't allocate list space...\n");
		exit(EXIT_FAILURE);
	}
	return p;
}

//R
char* getName(NODE* person) {
	return person->name;
}

void printPeople(PEOPLE* people) {
	NODE* person = people->head;

	while (person != NULL) {
		//get weights
		int* weaponWeights = readWeightsFromFile(getName(person));

		//determine weapon type
		int weaponNumber = determineWeapon(weaponWeights);
		printf("%s's weapon is: %s\n", getName(person), getWeapon(weaponNumber));

		//increment weapon weights
		increaseWeaponWeights(weaponWeights, weaponNumber);

		//write new weights to file
		writeWeightsToFile(getName(person), weaponWeights);

		person = person->next;
	}
}

//U
void add(PEOPLE* people, char* newName) {
	NODE* newPerson = (NODE*)malloc(sizeof(NODE));

	if (newPerson == NULL) {
		perror("Couldn't allocate person space...\n");
		exit(EXIT_FAILURE);
	}

	//set name
	strncpy(newPerson->name, newName, LENGTH);

	if (people->head == NULL) {
		newPerson->next = people->head;
		people->head = newPerson;
		return;
	}

	//add new person to end of list
	NODE* prev = people->head;
	NODE* tmp = people->head->next;

	while (tmp != NULL) {
		prev = tmp;
		tmp = tmp->next;
	}

	newPerson->next = NULL;
	prev->next = newPerson;

	//stack implementation
	//newPerson->next = people->head;
	//people->head = newPerson;
}

//D
void destroyPeople(PEOPLE* people) {
	while (people->head != NULL) {
		NODE* prev = people->head;
		people->head = people->head->next;
		free(prev);
	}
	free(people);
}