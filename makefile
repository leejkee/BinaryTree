main:Queue.o Bintree.o Array.o Stack.o
	gcc -o main -g main.c Queue.o Bintree.o Array.o Stack.o
Queue.o:
	gcc -c src/Queue.c
Bintree.o:
	gcc -c src/Bintree.c
Array.o:
	gcc -c src/Array.c
Stack.o:
	gcc -c src/Stack.c
clean:
	rm -f *.o