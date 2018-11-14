/**
 * Castle
 */

#include <stdio.h>
#include <stdlib.h>
#include "room.h"
#include "systempause.h"

int main() {
	FILE *file;
	Room map[82];

	loadMap( file, map );

	for (Room *m=map,*end=map+82; m<end; ++m) {
		system("clear");
		displayRoom(m);
		SystemPause();
	}

	return EXIT_SUCCESS;
}

void displayRoom( Room *map ) {
	for (int i = 0; i < 18; ++i) {
		printf("%.24s\n", map->map[i]);
	}
	for (int i = 0; i < 5; ++i) {
		printf("%.25s\n", map->description[i]);
	}
}

void loadMap( FILE *file, Room *map ) {
	file = fopen("CASTLE.RAN", "r");
	if (file==NULL) {
		fputs("File error\n",stderr);
		exit(EXIT_FAILURE);
	}
	for (Room *m=map,*end=map+82; m<end; ++m) {
		fread(m->map, 432, 1, file);
		fread(m->description, 125, 1, file);
		fread(m->nav, 18, 1, file);
	}
	fclose (file);
}
