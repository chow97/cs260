OBJS	= hash.o person.o personmgr.o personnel.o
SOURCE	= hash.cpp person.cpp personmgr.cpp personnel.cpp
HEADER	= hash.h person.h personmgr.h
OUT	= test
CC	 = g++
FLAGS	 = -g -c -Wall
LFLAGS	 = 

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

hash.o: hash.cpp
	$(CC) $(FLAGS) hash.cpp 

person.o: person.cpp
	$(CC) $(FLAGS) person.cpp 

personmgr.o: personmgr.cpp
	$(CC) $(FLAGS) personmgr.cpp 

personnel.o: personnel.cpp
	$(CC) $(FLAGS) personnel.cpp 


clean:
	rm -f $(OBJS) $(OUT)
