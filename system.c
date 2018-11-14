#include <stdio.h>
#include <stdlib.h>
#include "system.h"

void SystemPause() {
	puts("\nPress Enter to continue...");
	while (getchar() != '\n') {}
}

void SystemClear() {
	system("clear");
}
