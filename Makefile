CC = gcc
FLAGS = -ansi -Wall -lncurses
OBJS = main.o fonctions.o
EXE = 2048
CMD_COMP = -lncurses

$(EXE) : $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(EXE) $(CMD_COMP)
	
main.o : main.c
	$(CC) $(FLAGS) -c main.c 
	
reponse.o : fonctions.c
	$(CC) $(FLAGS) -c fonctions.c 
