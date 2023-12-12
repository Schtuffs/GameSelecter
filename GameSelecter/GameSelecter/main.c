#include "constants.h"

const char* mainGames[] = {""};
const int totalMainGames = sizeof(mainGames) / sizeof(*mainGames);

const char* allGames[] = {""};

const int totalAllGames = sizeof(allGames) / sizeof(*allGames);

int compare(const void* a, const void* b) {
	return strcmp(*(char**)a, *(char**)b);
}

int main() {
	srand((unsigned)time(NULL));

	qsort(mainGames, totalMainGames, sizeof(*mainGames), compare);
	qsort(allGames, totalAllGames, sizeof(*allGames), compare);

	printf("Choose your main games or all games:\n");
	printf("%d) Main\n", MAIN);
	printf("%d) All\n", ALL);
	printf("%d) Exit\n", EXITCODE);

	int userInput;
	if (scanf("%d", &userInput) != 1)
		printf("You're a failure and you should feel bad.\n");

	switch (userInput) {
	case MAIN:
		printf("You will play: %s\n", mainGames[rand() % totalMainGames]);
		break;
	case ALL:
		printf("You will play: %s\n", allGames[rand() % totalAllGames]);
		break;
	default:
		printf("Did you see that as an option moron?\n");
		break;
	}
	return 0;
}