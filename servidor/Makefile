#MakeFile
#Universidad Simon Bolivar
#Autor: David Lilue
#Carnet: 09-10444

CC = gcc
OPS = -ggdb -O3
MAIN = main2.c
DEPS = funciones.h Hashtable.h Lista.h queue.h
OBJS = funciones.o Hashtable.o Lista.o queue.o main2.o

schat: $(OBJS)
	$(CC) $(OPS) $(MAIN) -o $@ 

%.o: %.c $(DEPS)
	$(CC) $(OPS) -c $<

clean:
	\rm -f *.o *.out *.txt schat nul
