OBJS	= testlist.o event.o linkedlist.o structuretype.o
SOURCE	= testlist.cpp event.cpp linkedlist.cpp structuretype.cpp
HEADER	= event.h linkedlist.h structuretype.h
OUT	= try
CC	 = g++
FLAGS	 = -g -c -Wall
LFLAGS	 = 

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

testlist.o: testlist.cpp
	$(CC) $(FLAGS) testlist.cpp 

event.o: event.cpp
	$(CC) $(FLAGS) event.cpp 

linkedlist.o: linkedlist.cpp
	$(CC) $(FLAGS) linkedlist.cpp 

structuretype.o: structuretype.cpp
	$(CC) $(FLAGS) structuretype.cpp 


clean:
	rm -f $(OBJS) $(OUT)
