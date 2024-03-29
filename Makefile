#MakeFile
#Universidad Simon Bolivar
#Autor: David Lilue
#Carnet: 09-10444

CC = gcc
OPS = -ggdb
CCHAT = cchat.c
SCHAT = schat.c
DEPS1 = func_cli.h
OBJS1 = func_cli.o cchat.o
DEPS2 = queue.h lista.h func_ser.h
OBJS2 = queue.o lista.o func_ser.o schat.o

all : cchat schat 

cchat: $(OBJS1)
	$(CC) $(OPS) $(CCHAT) -o $@

schat: $(OBJS2)
	$(CC) $(OPS) $(SCHAT) -o $@ 

%.o: %.c $(DEPS1+DEPS2)
	$(CC) -c $<

clean:
	\rm -f *.o *.out *.txt cchat schat [0-9]* nul
