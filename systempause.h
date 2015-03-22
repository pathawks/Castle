#ifndef SYSTEM_PAUSE_H
#define SYSTEM_PAUSE_H

#include <stdio.h>

void SystemPause()
{
	printf("\n");
	printf("Press Enter to continue...");
    while (getchar() != '\n') {}
}

#endif
