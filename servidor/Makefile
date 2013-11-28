#MakeFile
#Universidad Simon Bolivar
#Autor: David Lilue
#Carnet: 09-10444

CC = gcc
OPS = -ggdb -O3
MAIN = main2.c
DEPS = Lista.h Hashtable.h queue.h funciones.h
OBJS = Lista.o Hashtable.o queue.o funciones.o main2.o

schat: $(OBJS)
	$(CC) $(OPS) $(MAIN) -o $@ 

%.o: %.c $(DEPS)
	$(CC) $(OPS) -c $<

clean:
	\rm -f *.o *.out *.txt schat nul
