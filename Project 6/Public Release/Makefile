deluser: func.o main.o
	gcc func.o main.o -o adduser
main.o: main.c func.h
	gcc -c main.c
func.o: func.c func.h
	gcc -c func.c
