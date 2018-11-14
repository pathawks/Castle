#ifndef CASTLE_ROOM_H
#define CASTLE_ROOM_H

typedef struct{
	char map[18][24];
	char description[5][25];
	char nav[18];
} Room;

void displayRoom( Room *map );
void loadMap( FILE *file, Room *map );

#endif
