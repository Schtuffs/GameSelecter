#include "constants.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "library.h"

//if there is a comment about a compiler error, and theres no error
//ignore and move on

int main() {
	//set time for random
	srand((unsigned)time(NULL));

	int userInput, totalRestricts = 0;
	int* restrictions = malloc(sizeof(int));

	if (restrictions == NULL)
		perror("Nalloc");

	//user enters which restrictions to add
	//more of 1 type is likely to make it easier
	//since it can roll multiple, can also roll same thing many times
	do {
		printf("Enter your limitations:\n");
		printf("%d) Character\n", CHARACTERRESTRICT);
		printf("%d) Weapon types\n", WEAPONRESTRICT);
		printf("%d) Manufacturer\n", MANURESTRICT);
		if (scanf("%d", &userInput) != 1) {
			printf("You moron, thats not a number...\n");
			char buf[STRINGLENGTH] = "";
			fgets(buf, STRINGLENGTH, stdin);
		}

		else if (userInput >= CURMAXRESTRICT) {
			printf("Too high...\n");
		}

		else {
			//compiler is straight up wrong
			restrictions[totalRestricts] = userInput;
			totalRestricts++;
							int* tmp = realloc(restrictions, (sizeof(int) + (totalRestricts * sizeof(int))));
			if (tmp == NULL) {
				free(restrictions);
				perror("Nrealloc...\n");
			}
			else
				restrictions = tmp;
			}

	} while (userInput != EXITCODE);

	//add requirements (compiler strikes again!)
	playthroughHell(restrictions, totalRestricts);

	//free vals
	free(restrictions);
	return 0;
}