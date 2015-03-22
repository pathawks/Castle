/**
 * Castle
 */

#include <stdio.h>
#include <stdlib.h>
#include "systempause.h"

int main() {
	FILE * MapFile;

	// Open Map File
	MapFile = fopen("CASTLE.RAN", "r");
	if (MapFile==NULL) {
		fputs ("File error",stderr);
		exit (EXIT_FAILURE);
	}

	char RoomMap[83][18][24];
	char RoomDescription[83][5][25];
	char RoomNav[83][18];

	for (int k = 1; k < 83; k++) {
		fread(RoomMap[k], 432, 1, MapFile);
		fread(RoomDescription[k], 125, 1, MapFile);
		fread(RoomNav[k], 18, 1, MapFile);

		for (int i = 0; i < 18; i++) {
			printf("%.24s\n", &RoomMap[k][i][0]);
		}

		for (int i = 0; i < 5; i++) {
			printf("%.25s\n", &RoomDescription[k][i][0]);
		}
		printf("\n");

		SystemPause();
		system("clear");
	}

	// terminate
	fclose (MapFile);
	return EXIT_SUCCESS;
}
