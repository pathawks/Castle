/**
 * Castle
 */

#include <stdio.h>
#include <stdlib.h>
#include "room.h"
#include "system.h"

int main() {
	FILE *file;
	Room map[82];

	loadMap( file, map );

	for (Room *m=map,*end=map+82; m<end; ++m) {
		SystemClear();
		displayRoom(m);
		SystemPause();
	}

	return EXIT_SUCCESS;
}

void displayRoom( Room *map ) {
	for (int i = 0; i < 18; ++i) {
		fwrite(map->map[i], 24, 1, stdout);
		fputc('\n', stdout);
	}
	for (int i = 0; i < 5; ++i) {
		fwrite(map->description[i], 25, 1, stdout);
		fputc('\n', stdout);
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
