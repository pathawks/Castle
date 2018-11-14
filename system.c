#include <stdio.h>
#include <stdlib.h>
#include "system.h"

void SystemPause() {
	puts("\nPress Enter to continue...");
	while (getchar() != '\n') {}
}

void SystemClear() {
	fputs("\033[2J\033[H", stdout);
}
