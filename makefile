all:
	gcc -g -c ListaEncadeada.c
	gcc -g -c HASH.c
	gcc -g main.c -o main ListaEncadeada.o HASH.o