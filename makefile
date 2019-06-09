EXE=Jeu

# compiler
CC=gcc
# debug
DEBUG=-g
# optimisation
OPT=-O0
# warnings
WARN=-Wall

PTHREAD=-pthread

CCFLAGS=$(DEBUG) $(OPT) $(WARN) $(PTHREAD) -pipe

GTKLIB=`pkg-config --cflags --libs gtk+-3.0`

# linker
LD=gcc
LDFLAGS=$(PTHREAD) $(GTKLIB) -export-dynamic

OBJS = main.o fonctions.o

$(EXE): $(OBJS)
	$(LD) -o $(EXE) $(OBJS) $(LDFLAGS)
    
main.o: src/main.c
	$(CC) -c $(CCFLAGS) src/main.c $(GTKLIB) -o main.o

reponse.o : src/fonctions.c
	$(CC) -c $(CCFLAGS) src/fonctions.c $(GTKLIB) -o fonctions.o
    
clean:
	rm -f *.o $(EXE)