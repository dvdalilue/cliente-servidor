#MakeFile
#Universidad Simon Bolivar
#Autor: David Lilue
#Carnet: 09-10444

CC = gcc
MAIN = main.c
DEPS = funciones.h
OBJS = funciones.o main.o

cchat: $(OBJS)
	$(CC) $(MAIN) -o $@ 

%.o: %.c $(DEPS)
	$(CC) -c $<

clean:
	\rm -f *.o *.out *.txt cchat nul
