#define _CRT_SECURE_NO_WARNINGS
#include "constants.h"
#include "library.h"
#include "person.h"

int main() {
	PEOPLE* people = createPersonList();
	people->head = NULL;

	add(people, "Calvin");
	add(people, "Kyle");

	setSeed();

	printPeople(people);

	destroyPeople(people);
	return 0;
}