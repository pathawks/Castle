/**
 * Castle
 */

#include <stdio.h>
#include <stdlib.h>
#include "room.h"
#include "systempause.h"

int main() {
	FILE *file;
	Room map[83];

	loadMap( file, map );

	for (int k = 1; k < 83; k++) {
		displayRoom(k, map);

		SystemPause();
		system("clear");
	}

	return EXIT_SUCCESS;
}

void displayRoom( int room, Room *map ) {
	for (int i = 0; i < 18; i++) {
		printf("%.24s\n", &map[room].map[i][0]);
	}
	for (int i = 0; i < 5; i++) {
		printf("%.25s\n", &map[room].description[i][0]);
	}
}

void loadMap( FILE *file, Room *map ) {
	file = fopen("CASTLE.RAN", "r");
	if (file==NULL) {
		fputs ("File error",stderr);
		exit (EXIT_FAILURE);
	}
	for (int k = 1; k < 83; k++) {
		fread(map[k].map, 432, 1, file);
		fread(map[k].description, 125, 1, file);
		fread(map[k].nav, 18, 1, file);
	}
	fclose (file);
}
