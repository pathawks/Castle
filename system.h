#ifndef SYSTEM_H
#define SYSTEM_H

#include <stdio.h>

void SystemPause() {
	puts("\nPress Enter to continue...");
	while (getchar() != '\n') {}
}

void SystemClear() {
	system("clear");
}

#endif
