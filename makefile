all: main clear

main: main.o resolucao.o entrada.o lista.o
	gcc lista.o entrada.o resolucao.o main.o -o tp2

main.o: main.c resolucao.h entrada.h lista.h
	gcc -g -c main.c

resolucao.o: resolucao.c resolucao.h
	gcc -g -c resolucao.c

entrada.o: entrada.c entrada.h
	gcc -g -c entrada.c

lista.o: lista.c lista.h
	gcc -g -c lista.c

clear:
	rm *.o
