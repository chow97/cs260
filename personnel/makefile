OBJS	= hash.o person.o personnel.o personmgr.o
SOURCE	= hash.cpp person.cpp personnel.cpp personmgr.cpp
HEADER	= hash.h person.h personmgr.h
OUT	= personnel
CC	 = g++
FLAGS	 = -g -c -Wall
LFLAGS	 = 

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

hash.o: hash.cpp
	$(CC) $(FLAGS) hash.cpp 

person.o: person.cpp
	$(CC) $(FLAGS) person.cpp 

personnel.o: personnel.cpp
	$(CC) $(FLAGS) personnel.cpp 

personmgr.o: personmgr.cpp
	$(CC) $(FLAGS) personmgr.cpp 
	
clean:
	rm -f $(OBJS) $(OUT)