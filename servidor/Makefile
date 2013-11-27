#MakeFile
#Universidad Simon Bolivar
#Autor: David Lilue
#Carnet: 09-10444

CC = gcc
OPS = -ggdb -O3
MAIN = main2.c
DEPS = funciones.c Hashtable.c Lista.c queue.c
OBJS = funciones.o Hashtable.o Lista.o queue.o

schat: $(OBJS)
	$(CC) $(OPS) $(MAIN) -o $@ 

%.o: %.c $(DEPS)
	$(CC) $(OPS) -c $<

clean:
	\rm -f *.o *.out *.txt schat nul
