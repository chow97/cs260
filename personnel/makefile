OBJS	= hash.o person.o testFunc.o personmgr.o
SOURCE	= hash.cpp person.cpp testFunc.cpp personmgr.cpp
HEADER	= hash.h person.h personmgr.h
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

personmgr.o: personmgr.cpp
	$(CC) $(FLAGS) personmgr.cpp 
	
clean:
	rm -f $(OBJS) $(OUT)