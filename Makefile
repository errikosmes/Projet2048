CC = gcc
FLAGS = -ansi -Wall 
OBJS = main.o fonctions.o
EXE = 2048

$(EXE) : $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(EXE)
	
main.o : main.c
	$(CC) $(FLAGS) -c main.c 
	
reponse.o : fonctions.c
	$(CC) $(FLAGS) -c fonctions.c 
