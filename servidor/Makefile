#MakeFile
#Universidad Simon Bolivar
#Autor: David Lilue
#Carnet: 09-10444

CC = gcc
OPS = -ggdb -O3
MAIN = main.c
DEPS = queue.h funciones.h
OBJS = queue.o funciones.o main.o

schat: $(OBJS)
	$(CC) $(OPS) $(MAIN) -o $@ 

%.o: %.c $(DEPS)
	$(CC) $(OPS) -c $<

clean:
	\rm -f *.o *.out *.txt schat nul
