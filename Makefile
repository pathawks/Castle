default: room

clean:
	rm -f room *.o

room.o: room.c room.h system.h
system.o: system.c system.h

room: room.o system.o
