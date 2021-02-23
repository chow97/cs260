OBJS	= builders.o event.o linkedlist.o structuretype.o stack.o
SOURCE	= builders.cpp event.cpp linkedlist.cpp structuretype.cpp stack.cpp
HEADER	= event.h linkedlist.h structuretype.h stack.h
OUT	= try
CC	 = g++
FLAGS	 = -g -c -Wall
LFLAGS	 = 

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

builders.o: builders.cpp
	$(CC) $(FLAGS) builders.cpp 

event.o: event.cpp
	$(CC) $(FLAGS) event.cpp 

linkedlist.o: linkedlist.cpp
	$(CC) $(FLAGS) linkedlist.cpp 

structuretype.o: structuretype.cpp
	$(CC) $(FLAGS) structuretype.cpp 

stack.o: stack.cpp
	$(CC) $(FLAGS) stack.cpp 


clean:
	rm -f $(OBJS) $(OUT)
