CFLAGS= -g -Wall
SDLFLAGS= `sdl-config --cflags --libs`
OBJ = main.o cell.o

rogue: $(OBJ)
	gcc $(CFLAGS) $(OBJ) -o rogue $(SDLFLAGS)

#perso.o:perso.c perso.h
#	gcc $(CFLAGS) -c perso.c

main.o: main.c $(wildcard *.h)
	gcc $(CFLAGS) -c main.c $(SDLFLAGS)

cell.o: cell.c cell.h perso.h core.h
	gcc $(CFLAGS) -c cell.c

tcell: test_cell.o cell.o
	gcc $(CFLAGS) test_cell.o cell.o -o tcell

test_cell.o: test_cell.c cell.h perso.h
	gcc $(CFLAGS) -c test_cell.c
	
	
	
clean:
	rm main.o cell.o
