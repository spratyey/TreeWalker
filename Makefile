$(CC) = gcc
final: node.o PriorityQueue.o adjacencylists.o pqtestmain.o
		$(CC) node.o PriorityQueue.o adjacencylists.o pqtestmain.o -o final

node.o: node.c node.h
		$(CC) -c node.c
PriorityQueue.o: PriorityQueue.c PriorityQueue.h node.h
		$(CC) -c PriorityQueue.c

adjacencylists.o: adjacencylists.c PriorityQueue.h node.h
		$(CC) -c adjacencylists.c
pqtestmain.o: pqtestmain.c PriorityQueue.h node.h
		$(CC) -c pqtestmain.c

clean:
		rm*.o final