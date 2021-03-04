OBJS	= hash.o person.o testFunc.o
SOURCE	= hash.cpp person.cpp testFunc.cpp
HEADER	= hash.h person.h
OUT	= testFunc
CC	 = g++
FLAGS	 = -g -c -Wall
LFLAGS	 = 

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

hash.o: hash.cpp
	$(CC) $(FLAGS) hash.cpp 

person.o: person.cpp
	$(CC) $(FLAGS) person.cpp 

testFunc.o: testFunc.cpp
	$(CC) $(FLAGS) testFunc.cpp 


clean:
	rm -f $(OBJS) $(OUT)