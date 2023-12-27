#include "constants.h"

const char* mainGames[] = { "Black Ops Cold War", "Borderlands 2", "Fortnite", "Hollow Knight", "Minecraft", "Modded Minecraft", "Monster Hunter", "Stardew", "Terraria", "Warframe" };
const int totalMainGames = sizeof(mainGames) / sizeof(*mainGames);

const char* allGames[] = { "Black Ops Cold War", "Bloons TD 6", "Borderlands 2", "Borderlands TPS", "Borderlands 3",
								"Deep Rock Galactic",
								"Elden Ring",
								"Fortnite",
								"God of War: Ragnarok", "GTA V",
								"Hollow Knight",
								"Leaf Blower Revolution",
								"Minecraft", "Modded Minecraft", "Monster Hunter",
								"Poly Bridge", "Poly Bridge 2", "Portal", "Portal 2", "Powerwash Simulator",
								"R6 Siege", "Slime Rancher", "Stardew",
								"Terraria",
								"Warframe" "Witcher 1", "Witcher 2", "Witcher 3" };

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
	case EXITCODE:
		printf("Aight, adios.\n");
		break;
	default:
		printf("Did you see that as an option moron?\n");
		break;
	}
	return 0;
}