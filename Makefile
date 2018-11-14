default: room

clean:
	rm -f room *.o

room.o: room.c room.h system.h

room: room.o
