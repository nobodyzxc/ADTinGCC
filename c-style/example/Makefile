all:
	gcc -g -c ../list.c ../node.c
	gcc -g -o declare declare.c list.o node.o
	gcc -g -o hof hof.c list.o node.o
	gcc -g -o main main.c list.o node.o
	#gcc -g -o main append.c list.o node.o
clean:
	rm -f *.exe list.o node.o 2>/dev/null
macro:
	gcc -g -E main.c
o:
	rm -f *.exe list.o node.o 2>/dev/null
	gcc -g -c ../list.c ../node.c
	gcc -g -o declare declare.c list.o node.o
	gcc -g -o hof hof.c list.o node.o
	gcc -g -o main main.c list.o node.o
	#gcc -g -o main append.c list.o node.o
