CC = gcc 
FLAGS = -Wall
OBJECTS_MAIN = main.o


all: StrList

StrList: $(OBJECTS_MAIN) StrList.o
	$(CC) $(FLAGS) $(OBJECTS_MAIN) StrList.o -o StrList

main.o: main.c StrList.h
	$(CC) $(FLAGS) -c main.c

StrList.o: StrList.c StrList.h
	$(CC)$(FLAGS) -c StrList.c 	

.PHONY: clean

clean:
	rm -f *.o StrList