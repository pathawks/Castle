#include <stdio.h>

void SystemPause()
{
	printf("Press Enter to continue...");
        while (getchar() != '\n');
}