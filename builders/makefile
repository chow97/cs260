OBJS	= builders.o event.o linkedlist.o structuretype.o stack.o builder.o
SOURCE	= builders.cpp event.cpp linkedlist.cpp structuretype.cpp stack.cpp builder.cpp
HEADER	= event.h linkedlist.h structuretype.h stack.h builder.h
OUT	= builders
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

builder.o: builder.cpp
	$(CC) $(FLAGS) builder.cpp 


clean:
	rm -f $(OBJS) $(OUT)