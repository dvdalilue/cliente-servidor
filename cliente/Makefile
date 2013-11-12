#MakeFile
#Universidad Simon Bolivar
#Autor: David Lilue
#Carnet: 09-10444

CC = gcc
MAIN = main.c
DEPS = funciones.c
OBJS = funciones.h main.o

cchat: $(OBJS)
	$(CC) $(MAIN) -o $@ 

%.o: %.c $(DEPS)
	$(CC) -c $<

check-syntax:
	$(CC) -o nul -S ${CHK_SOURCES}

clean:
	\rm -f *.o *.out *.txt cchat nul