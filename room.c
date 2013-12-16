/* Hello World program */

#include <stdio.h>
#include <stdlib.h>
#include "systempause.h"

int main()
{
FILE * MapFile;

// Open Map File
MapFile = fopen("CASTLE.RAN", "r");
if (MapFile==NULL) {fputs ("File error",stderr); exit (1);}

char RoomMap[83][18][24];
char RoomDescription[83][5][25];
char RoomNav[83][18];


int i, j, k;

for (k = 1; k < 83; k++) {

fread(RoomMap[k], 432, 1, MapFile);
fread(RoomDescription[k], 125, 1, MapFile);
fread(RoomNav[k], 18, 1, MapFile);

for (i = 0; i < 18; i++) {
	//loop through second dimension
	for (j = 0; j < 24; j++) {
	  //print each array element.
	  printf("%c", RoomMap[k][i][j]);
	}
	
	//Add newline at end to ensure each row gets printed correctly.
	printf("\n");
}

for (i = 0; i < 5; i++) {
	for (j = 0; j < 25; j++) {
		printf("%c", RoomDescription[k][i][j]);
	}
	printf("\n");
}
printf("\n");

SystemPause();
system("clear");

}

fclose(MapFile);


// terminate
fclose (MapFile);
return 0;
}