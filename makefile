main:queue.o tree.o
	gcc -o main -g main.c queue.o tree.o
queue.o:
	gcc -c queue.c
tree.o:
	gcc -c tree.c
clean:
	rm -f *.o