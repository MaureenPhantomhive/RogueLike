mapping : mapping.o fonction_finie.o
	gcc -g mapping.o fonction_finie.o -o mapping

mapping.o : mapping.c
	gcc -g -c mapping.c

fonction_finie.o : fonction_finie.c
	gcc -g -c fonction_finie.c
