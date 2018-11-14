/**
 * Castle
 */

#include <stdio.h>
#include <stdlib.h>
#include "room.h"
#include "system.h"

int main() {
	Room map[82];
	FILE *file = openMap("CASTLE.RAN");
	loadMap( file, map );
	fclose (file);

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
//	for (Room *m=map,*end=map+82; m<end; ++m) {
//		fread(m->map, 18*24, 1, file);
//		fread(m->description, 5*25, 1, file);
//		fread(m->nav, 18, 1, file);
//	}
	fread(map, (18*24+5*25+18)*82, 1, file);
}

FILE* openMap( char* name ) {
	FILE *file = fopen(name, "r");
	if (file==NULL) {
		fputs("File error\n",stderr);
		exit(EXIT_FAILURE);
	}
	return file;
}
