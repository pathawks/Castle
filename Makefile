default: room

clean:
	rm -f room *.o

room.o: room.c room.h systempause.h

room: room.o
