all:
	gcc -g -c list.c node.c
	gcc -g main.c list.o node.o
#-D';'=';'
clean:
	-rm a.exe list.o node.o 2>/dev/null

macro:
	gcc -g -E main.c
o:
	rm a.exe list.o node.o 2>/dev/null
	gcc -g -c list.c node.c
	gcc -g main.c list.o node.o
