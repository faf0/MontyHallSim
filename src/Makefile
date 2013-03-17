CC = gcc
CPP = g++
CPPFLAGS += -I./ -Wall -Wsign-compare -Wchar-subscripts -Werror -pedantic
CFLAGS += -std=c99
#CXXFLAGS += -O2
LDFLAGS  += -L./
LOADLIBES = -lm

.PHONY: all, clean

PROGNAME := monty_hall_sim 

all:	monty_hall_sim
monty_hall_sim:	monty_hall_sim.o

clean:
	rm *.o monty_hall_sim
