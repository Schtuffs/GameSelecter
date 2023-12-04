#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "library.h"
#define LENGTH	20

int main()
{
	int Select = GetInput();
	char ClassType[20];
	strncpy(ClassType, GetClass(), LENGTH);
	char SubClassType[LENGTH];

	if (Select == 2)
		strncpy(SubClassType, GetSubClass(ClassType), LENGTH);
	else
		strncpy(SubClassType, "", LENGTH);

	PrintClassType(ClassType, SubClassType);
	return 0;
}